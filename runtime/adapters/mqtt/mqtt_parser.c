#include "runtime/adapters/mqtt/mqtt_parser.h"

#include <string.h>

int stich_mqtt_parse_payload(const char *payload, stich_telemetry_event_t *telemetry_event) {
    if (payload == NULL || telemetry_event == NULL) {
        return -1;
    }

    /* The parser is intentionally simple for the PoC scaffold.
     * We treat the entire payload as the measurement value until a real
     * protocol-specific parser is introduced. */
    strncpy(telemetry_event->value, payload, sizeof(telemetry_event->value) - 1U);
    telemetry_event->value[sizeof(telemetry_event->value) - 1U] = '\0';

    strncpy(telemetry_event->unit, "raw", sizeof(telemetry_event->unit) - 1U);
    telemetry_event->unit[sizeof(telemetry_event->unit) - 1U] = '\0';

    return 0;
}
