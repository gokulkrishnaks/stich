#include "runtime/observability/metrics.h"

#include <stddef.h>

void stich_metrics_init(stich_metrics_t *metrics) {
    if (metrics == NULL) {
        return;
    }

    /* Reset all counters at startup so each run starts from a known state. */
    metrics->ingested_events = 0U;
    metrics->routed_events = 0U;
}

void stich_metrics_record_ingest(stich_metrics_t *metrics) {
    if (metrics == NULL) {
        return;
    }

    /* Count events as soon as they enter the canonical runtime path. */
    metrics->ingested_events += 1U;
}

void stich_metrics_record_route(stich_metrics_t *metrics) {
    if (metrics == NULL) {
        return;
    }

    /* Count events again once the router has successfully handled them. */
    metrics->routed_events += 1U;
}
