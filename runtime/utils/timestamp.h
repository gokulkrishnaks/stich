#ifndef STICH_RUNTIME_UTILS_TIMESTAMP_H
#define STICH_RUNTIME_UTILS_TIMESTAMP_H

#include <stddef.h>

#include "runtime/events/event_types.h"

/* Produces a printable local timestamp for logs and event metadata. */
void stich_timestamp_now(char *buffer, size_t buffer_size);

#endif
