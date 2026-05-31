
#include "canonical/normalization/normalization.h"
#include <time.h>

uint64_t current_us(void){
    struct timespec ts;
    timespec_get(&ts, TIME_UTC); 
    return (uint64_t)ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000ULL;
}


int stich_normalize(stich_frame_t *frame){
    frame->timestamp_us = current_us();
    
    return(frame->state = STICH_FRAME_STATE_CANONICAL);
}