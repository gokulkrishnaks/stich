#ifndef STICH_RUNTIME_ADAPTERS_MQTT_MQTT_ADAPTER_H
#define STICH_RUNTIME_ADAPTERS_MQTT_MQTT_ADAPTER_H

#include "runtime/adapters/adapter.h"

/* The MQTT adapter keeps only a tiny bit of state in the PoC so outbound
 * command dispatches can be observed. */
typedef struct stich_mqtt_adapter_context {
    unsigned int published_commands;
} stich_mqtt_adapter_context_t;

/* Wires MQTT-specific ingest/dispatch callbacks into the generic adapter
 * interface used by the runtime core. */
void stich_mqtt_adapter_init(stich_adapter_t *adapter, stich_mqtt_adapter_context_t *context);

#endif
