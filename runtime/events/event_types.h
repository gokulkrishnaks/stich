#ifndef STICH_RUNTIME_EVENTS_EVENT_TYPES_H
#define STICH_RUNTIME_EVENTS_EVENT_TYPES_H

#include <stddef.h>

#define STICH_MAX_ID_LENGTH 64
#define STICH_MAX_TOPIC_LENGTH 128
#define STICH_MAX_PAYLOAD_LENGTH 256
#define STICH_MAX_MESSAGE_LENGTH 512

typedef enum stich_event_kind {
    STICH_EVENT_TELEMETRY = 0,
    STICH_EVENT_COMMAND = 1,
    STICH_EVENT_NODE_STATUS = 2
} stich_event_kind_t;

typedef struct stich_event_metadata {
    char event_id[STICH_MAX_ID_LENGTH];
    char node_id[STICH_MAX_ID_LENGTH];
    char source[STICH_MAX_ID_LENGTH];
    char timestamp[STICH_MAX_ID_LENGTH];
} stich_event_metadata_t;

typedef struct stich_telemetry_event {
    char metric[STICH_MAX_TOPIC_LENGTH];
    char value[STICH_MAX_PAYLOAD_LENGTH];
    char unit[32];
} stich_telemetry_event_t;

typedef struct stich_command_event {
    char command_name[STICH_MAX_TOPIC_LENGTH];
    char target[STICH_MAX_ID_LENGTH];
    char argument[STICH_MAX_PAYLOAD_LENGTH];
} stich_command_event_t;

typedef struct stich_node_event {
    char status[32];
    char capability[STICH_MAX_TOPIC_LENGTH];
} stich_node_event_t;

typedef struct stich_event {
    stich_event_kind_t kind;
    stich_event_metadata_t metadata;
    union {
        stich_telemetry_event_t telemetry;
        stich_command_event_t command;
        stich_node_event_t node;
    } data;
} stich_event_t;

int stich_event_serialize(const stich_event_t *event, char *buffer, size_t buffer_size);
const char *stich_event_kind_to_string(stich_event_kind_t kind);

#endif
