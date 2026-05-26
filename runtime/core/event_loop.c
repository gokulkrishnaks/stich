#include "runtime/core/event_loop.h"

#include "runtime/core/router.h"
#include "runtime/observability/logger.h"

int stich_event_loop_run(
    stich_adapter_t *adapter,
    stich_metrics_t *metrics,
    const char *topic,
    const char *payload
) {
    stich_event_t event;

    if (adapter == NULL || adapter->ingest == NULL) {
        stich_log(STICH_LOG_ERROR, "event_loop", "adapter is not ready");
        return -1;
    }

    /* The first PoC loop handles a single message path end-to-end so we can
     * verify ingestion, normalization, and routing before adding concurrency
     * or broker integration complexity. */
    if (adapter->ingest(adapter, topic, payload, &event) != 0) {
        stich_log(STICH_LOG_ERROR, "event_loop", "ingestion failed");
        return -1;
    }

    /* Once the adapter has produced a canonical event, the runtime can start
     * tracking it without needing to know anything about MQTT. */
    stich_metrics_record_ingest(metrics);
    return stich_router_route(&event, metrics);
}
