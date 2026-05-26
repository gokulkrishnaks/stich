#ifndef STICH_RUNTIME_OBSERVABILITY_LOGGER_H
#define STICH_RUNTIME_OBSERVABILITY_LOGGER_H

typedef enum stich_log_level {
    STICH_LOG_DEBUG = 0,
    STICH_LOG_INFO = 1,
    STICH_LOG_WARN = 2,
    STICH_LOG_ERROR = 3
} stich_log_level_t;

void stich_logger_init(void);
void stich_log(stich_log_level_t level, const char *component, const char *message);

#endif
