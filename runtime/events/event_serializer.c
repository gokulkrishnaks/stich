#include "runtime/events/event_types.h"

#include <stdio.h>

const char *stich_event_kind_to_string(stich_event_kind_t kind) {
    switch (kind) {
        case STICH_EVENT_TELEMETRY:
            return "telemetry";
        case STICH_EVENT_COMMAND:
            return "command";
        case STICH_EVENT_NODE_STATUS:
            return "node_status";
        default:
            return "unknown";
    }
}

int stich_event_serialize(const stich_event_t *event, char *buffer, size_t buffer_size) {
    if (event == NULL || buffer == NULL || buffer_size == 0U) {
        return -1;
    }

    switch (event->kind) {
        case STICH_EVENT_TELEMETRY:
            return snprintf(
                buffer,
                buffer_size,
                "{kind:%s,event_id:%s,node_id:%s,metric:%s,value:%s,unit:%s,timestamp:%s}",
                stich_event_kind_to_string(event->kind),
                event->metadata.event_id,
                event->metadata.node_id,
                event->data.telemetry.metric,
                event->data.telemetry.value,
                event->data.telemetry.unit,
                event->metadata.timestamp
            );
        case STICH_EVENT_COMMAND:
            return snprintf(
                buffer,
                buffer_size,
                "{kind:%s,event_id:%s,target:%s,command:%s,argument:%s,timestamp:%s}",
                stich_event_kind_to_string(event->kind),
                event->metadata.event_id,
                event->data.command.target,
                event->data.command.command_name,
                event->data.command.argument,
                event->metadata.timestamp
            );
        case STICH_EVENT_NODE_STATUS:
            return snprintf(
                buffer,
                buffer_size,
                "{kind:%s,event_id:%s,node_id:%s,status:%s,capability:%s,timestamp:%s}",
                stich_event_kind_to_string(event->kind),
                event->metadata.event_id,
                event->metadata.node_id,
                event->data.node.status,
                event->data.node.capability,
                event->metadata.timestamp
            );
        default:
            return snprintf(buffer, buffer_size, "{kind:unknown}");
    }
}
