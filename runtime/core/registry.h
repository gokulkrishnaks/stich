#ifndef STICH_RUNTIME_CORE_REGISTRY_H
#define STICH_RUNTIME_CORE_REGISTRY_H

#include "runtime/adapters/adapter.h"

/* The first PoC only needs a single primary adapter, but the registry keeps
 * the ownership point explicit for later expansion. */
typedef struct stich_adapter_registry {
    stich_adapter_t *primary_adapter;
} stich_adapter_registry_t;

void stich_registry_register_primary(stich_adapter_registry_t *registry, stich_adapter_t *adapter);

#endif
