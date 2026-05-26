#include "runtime/observability/logger.h"

#include "runtime/utils/timestamp.h"

#include <stdio.h>

static const char *stich_log_level_name(stich_log_level_t level) {
    switch (level) {
        case STICH_LOG_DEBUG:
            return "DEBUG";
        case STICH_LOG_INFO:
            return "INFO";
        case STICH_LOG_WARN:
            return "WARN";
        case STICH_LOG_ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

void stich_logger_init(void) {
    stich_log(STICH_LOG_INFO, "logger", "structured logger ready");
}

void stich_log(stich_log_level_t level, const char *component, const char *message) {
    char timestamp[STICH_MAX_ID_LENGTH];

    stich_timestamp_now(timestamp, sizeof(timestamp));
    printf("[%s] level=%s component=%s message=\"%s\"\n",
           timestamp,
           stich_log_level_name(level),
           component,
           message);
}
