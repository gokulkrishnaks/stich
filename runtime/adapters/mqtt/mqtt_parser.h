#ifndef STICH_RUNTIME_ADAPTERS_MQTT_MQTT_PARSER_H
#define STICH_RUNTIME_ADAPTERS_MQTT_MQTT_PARSER_H

#include "runtime/events/event_types.h"

int stich_mqtt_parse_payload(const char *payload, stich_telemetry_event_t *telemetry_event);

#endif
