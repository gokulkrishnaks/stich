#include "runtime/core/runtime.h"

#include "runtime/adapters/mqtt/mqtt_adapter.h"
#include "runtime/core/event_loop.h"
#include "runtime/core/registry.h"
#include "runtime/observability/logger.h"
#include "runtime/observability/metrics.h"
#include "runtime/utils/config.h"

#include <stdio.h>

int stich_runtime_start(void) {
    stich_runtime_config_t config;
    stich_metrics_t metrics;
    stich_adapter_registry_t registry;
    stich_mqtt_adapter_context_t mqtt_context;
    stich_adapter_t mqtt_adapter;
    char startup_message[STICH_MAX_MESSAGE_LENGTH];

    /* Startup follows the same order the real runtime would need: logging
     * first, configuration next, then adapters and event processing. */
    stich_logger_init();
    stich_config_load_defaults(&config);
    stich_metrics_init(&metrics);

    stich_mqtt_adapter_init(&mqtt_adapter, &mqtt_context);
    stich_registry_register_primary(&registry, &mqtt_adapter);

    snprintf(startup_message,
             sizeof(startup_message),
             "runtime=%s booting with primary_adapter=%s topic=%s",
             config.runtime_id,
             registry.primary_adapter->name,
             config.mqtt_topic);
    stich_log(STICH_LOG_INFO, "runtime", startup_message);

    /* The PoC injects a sample payload instead of reading from a live broker so
     * the full runtime path remains easy to build and test locally. */
    return stich_event_loop_run(registry.primary_adapter, &metrics, config.mqtt_topic, "24.7");
}

int main(void) {
    int result;

    /* Keep `main` intentionally tiny so the reusable startup path remains in
     * `stich_runtime_start` for tests and future embedding. */
    result = stich_runtime_start();
    if (result != 0) {
        fprintf(stderr, "STICH runtime failed to start\n");
        return 1;
    }

    return 0;
}
