
#include "canonical/validation/validation.h"

int stich_frame_validation(stich_frame_t *frame){
    if (frame == NULL) return -1;

    return (frame -> payload_len > 0) && (frame -> payload_len <= STICH_PAYLOAD_MAX) &&
           (frame->kind <= STICH_FRAME_KIND_ERROR) && (frame->schema = STICH_FRAME_STATE_DEAD);
}