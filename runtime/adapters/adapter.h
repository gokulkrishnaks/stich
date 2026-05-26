#ifndef STICH_RUNTIME_ADAPTERS_ADAPTER_H
#define STICH_RUNTIME_ADAPTERS_ADAPTER_H

#include "runtime/events/event_types.h"

/* Adapters form the boundary between protocol-specific I/O and the canonical
 * runtime event model. */
typedef struct stich_adapter {
    const char *name;
    int (*ingest)(struct stich_adapter *adapter, const char *topic, const char *payload, stich_event_t *event);
    int (*dispatch)(struct stich_adapter *adapter, const stich_event_t *event);
    void *context;
} stich_adapter_t;

#endif
