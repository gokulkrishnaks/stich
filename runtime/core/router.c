#include "runtime/core/router.h"

#include "runtime/observability/logger.h"

int stich_router_route(const stich_event_t *event, stich_metrics_t *metrics) {
    char serialized_event[STICH_MAX_MESSAGE_LENGTH];

    if (event == NULL) {
        return -1;
    }

    /* Serializing before logging gives us one stable textual representation of
     * an event that can later be reused by tests or other sinks. */
    stich_event_serialize(event, serialized_event, sizeof(serialized_event));
    stich_log(STICH_LOG_INFO, "router", serialized_event);
    stich_metrics_record_route(metrics);
    return 0;
}
