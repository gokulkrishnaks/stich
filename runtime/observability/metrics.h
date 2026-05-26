#ifndef STICH_RUNTIME_OBSERVABILITY_METRICS_H
#define STICH_RUNTIME_OBSERVABILITY_METRICS_H

/* These counters are intentionally simple: the first PoC only needs a tiny
 * bit of observability to prove the runtime path is being exercised. */
typedef struct stich_metrics {
    unsigned int ingested_events;
    unsigned int routed_events;
} stich_metrics_t;

void stich_metrics_init(stich_metrics_t *metrics);
void stich_metrics_record_ingest(stich_metrics_t *metrics);
void stich_metrics_record_route(stich_metrics_t *metrics);

#endif
