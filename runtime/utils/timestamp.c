#include "runtime/utils/timestamp.h"

#include <stdio.h>
#include <time.h>

void stich_timestamp_now(char *buffer, size_t buffer_size) {
    time_t now;
    struct tm *time_info;

    if (buffer == NULL || buffer_size == 0U) {
        return;
    }

    now = time(NULL);
    time_info = localtime(&now);
    if (time_info == NULL) {
        snprintf(buffer, buffer_size, "1970-01-01T00:00:00+0000");
        return;
    }

    strftime(buffer, buffer_size, "%Y-%m-%dT%H:%M:%S%z", time_info);
}
