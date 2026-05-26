#include "runtime/observability/metrics.h"

#include <stddef.h>

void stich_metrics_init(stich_metrics_t *metrics) {
    if (metrics == NULL) {
        return;
    }

    metrics->ingested_events = 0U;
    metrics->routed_events = 0U;
}

void stich_metrics_record_ingest(stich_metrics_t *metrics) {
    if (metrics == NULL) {
        return;
    }

    metrics->ingested_events += 1U;
}

void stich_metrics_record_route(stich_metrics_t *metrics) {
    if (metrics == NULL) {
        return;
    }

    metrics->routed_events += 1U;
}
