#ifndef STICH_VALIDATION_H
#define STICH_VALIDATION_H

#include <stdint.h>
#include <stddef.h>
#include "canonical/envelope/frame.h"

int stich_frame_validation(stich_frame_t *frame);

#endif