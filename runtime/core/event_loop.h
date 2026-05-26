#ifndef STICH_RUNTIME_CORE_EVENT_LOOP_H
#define STICH_RUNTIME_CORE_EVENT_LOOP_H

#include "runtime/adapters/adapter.h"
#include "runtime/observability/metrics.h"

int stich_event_loop_run(stich_adapter_t *adapter, stich_metrics_t *metrics, const char *topic, const char *payload);

#endif
