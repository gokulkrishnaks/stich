#include "runtime/utils/config.h"

#include <string.h>

void stich_config_load_defaults(stich_runtime_config_t *config) {
    if (config == NULL) {
        return;
    }

    /* These defaults give the runtime a stable identity and topic path without
     * introducing configuration-file parsing in the first public push. */
    strncpy(config->runtime_id, "stich-edge-dev", sizeof(config->runtime_id) - 1U);
    config->runtime_id[sizeof(config->runtime_id) - 1U] = '\0';

    strncpy(config->mqtt_topic, "factory/line-1/temperature", sizeof(config->mqtt_topic) - 1U);
    config->mqtt_topic[sizeof(config->mqtt_topic) - 1U] = '\0';

    strncpy(config->mqtt_source, "mqtt-adapter", sizeof(config->mqtt_source) - 1U);
    config->mqtt_source[sizeof(config->mqtt_source) - 1U] = '\0';
}
