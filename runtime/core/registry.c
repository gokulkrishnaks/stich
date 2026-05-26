#include "runtime/core/registry.h"

void stich_registry_register_primary(stich_adapter_registry_t *registry, stich_adapter_t *adapter) {
    if (registry == NULL) {
        return;
    }

    /* The runtime reads adapters through the registry rather than holding
     * hard-coded globals. */
    registry->primary_adapter = adapter;
}
