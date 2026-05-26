#ifndef STICH_RUNTIME_CORE_REGISTRY_H
#define STICH_RUNTIME_CORE_REGISTRY_H

#include "runtime/adapters/adapter.h"

typedef struct stich_adapter_registry {
    stich_adapter_t *primary_adapter;
} stich_adapter_registry_t;

void stich_registry_register_primary(stich_adapter_registry_t *registry, stich_adapter_t *adapter);

#endif
