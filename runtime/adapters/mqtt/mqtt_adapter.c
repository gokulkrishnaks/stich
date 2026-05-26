#include "runtime/adapters/mqtt/mqtt_adapter.h"

#include "runtime/adapters/mqtt/mqtt_parser.h"
#include "runtime/observability/logger.h"
#include "runtime/utils/timestamp.h"

#include <stdio.h>
#include <string.h>

static int stich_mqtt_adapter_ingest(
    stich_adapter_t *adapter,
    const char *topic,
    const char *payload,
    stich_event_t *event
) {
    int parsed;

    if (adapter == NULL || topic == NULL || payload == NULL || event == NULL) {
        return -1;
    }

    memset(event, 0, sizeof(*event));
    event->kind = STICH_EVENT_TELEMETRY;

    /* The adapter is where protocol-specific inputs become canonical runtime
     * events. Keeping that translation here prevents the runtime core from
     * learning protocol details. */
    strncpy(event->metadata.event_id, "evt-mqtt-001", sizeof(event->metadata.event_id) - 1U);
    strncpy(event->metadata.node_id, "edge-node-01", sizeof(event->metadata.node_id) - 1U);
    strncpy(event->metadata.source, adapter->name, sizeof(event->metadata.source) - 1U);
    strncpy(event->data.telemetry.metric, topic, sizeof(event->data.telemetry.metric) - 1U);
    stich_timestamp_now(event->metadata.timestamp, sizeof(event->metadata.timestamp));

    parsed = stich_mqtt_parse_payload(payload, &event->data.telemetry);
    if (parsed != 0) {
        stich_log(STICH_LOG_ERROR, "mqtt_adapter", "failed to parse inbound payload");
        return -1;
    }

    return 0;
}

static int stich_mqtt_adapter_dispatch(stich_adapter_t *adapter, const stich_event_t *event) {
    stich_mqtt_adapter_context_t *context;
    char log_message[STICH_MAX_MESSAGE_LENGTH];

    if (adapter == NULL || event == NULL || adapter->context == NULL) {
        return -1;
    }

    context = (stich_mqtt_adapter_context_t *)adapter->context;
    context->published_commands += 1U;

    snprintf(log_message,
             sizeof(log_message),
             "dispatch placeholder invoked for event kind=%s total_publishes=%u",
             stich_event_kind_to_string(event->kind),
             context->published_commands);
    stich_log(STICH_LOG_INFO, "mqtt_adapter", log_message);
    return 0;
}

void stich_mqtt_adapter_init(stich_adapter_t *adapter, stich_mqtt_adapter_context_t *context) {
    if (adapter == NULL || context == NULL) {
        return;
    }

    context->published_commands = 0U;
    adapter->name = "mqtt-adapter";
    adapter->ingest = stich_mqtt_adapter_ingest;
    adapter->dispatch = stich_mqtt_adapter_dispatch;
    adapter->context = context;
}
