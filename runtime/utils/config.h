#ifndef STICH_RUNTIME_UTILS_CONFIG_H
#define STICH_RUNTIME_UTILS_CONFIG_H

#include "runtime/events/event_types.h"

typedef struct stich_runtime_config {
    char runtime_id[STICH_MAX_ID_LENGTH];
    char mqtt_topic[STICH_MAX_TOPIC_LENGTH];
    char mqtt_source[STICH_MAX_ID_LENGTH];
} stich_runtime_config_t;

void stich_config_load_defaults(stich_runtime_config_t *config);

#endif
