#ifndef STICH_RUNTIME_ADAPTERS_MQTT_MQTT_ADAPTER_H
#define STICH_RUNTIME_ADAPTERS_MQTT_MQTT_ADAPTER_H

#include "runtime/adapters/adapter.h"

typedef struct stich_mqtt_adapter_context {
    unsigned int published_commands;
} stich_mqtt_adapter_context_t;

void stich_mqtt_adapter_init(stich_adapter_t *adapter, stich_mqtt_adapter_context_t *context);

#endif
