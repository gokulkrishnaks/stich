#ifndef STICH_RUNTIME_CORE_ROUTER_H
#define STICH_RUNTIME_CORE_ROUTER_H

#include "runtime/events/event_types.h"
#include "runtime/observability/metrics.h"

/* Routes a canonical event through the current runtime output path. In the PoC
 * that means structured logging plus metric updates. */
int stich_router_route(const stich_event_t *event, stich_metrics_t *metrics);

#endif
