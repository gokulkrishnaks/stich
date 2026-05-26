#ifndef STICH_RUNTIME_ADAPTERS_MQTT_MQTT_PARSER_H
#define STICH_RUNTIME_ADAPTERS_MQTT_MQTT_PARSER_H

#include "runtime/events/event_types.h"

/* Converts an MQTT payload string into the canonical telemetry payload fields
 * used by the rest of the runtime. */
int stich_mqtt_parse_payload(const char *payload, stich_telemetry_event_t *telemetry_event);

#endif
