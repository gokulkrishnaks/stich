#ifndef STICH_FRAME_H
#define STICH_FRAME_H

#include <stdint.h>
#include <stddef.h>

#define STICH_PAYLOAD_MAX 256

typedef enum{
    STICH_FRAME_KIND_TELEMETRY  = 0,
    STICH_FRAME_KIND_COMMAND    = 1,
    STICH_FRAME_KIND_ACK        = 2,
    STICH_FRAME_KIND_ERROR      = 3
}stich_frame_kind_t;

typedef enum{
    STICH_FRAME_STATE_CANDIDATE     = 0,
    STICH_FRAME_STATE_CANONICAL     = 1,
    STICH_FRAME_STATE_ROUTING       = 2,
    STICH_FRAME_STATE_DELIVERING    = 3,
    STICH_FRAME_STATE_DELIVERED     = 4,
    STICH_FRAME_STATE_DEAD          = 5,
}stich_frame_state_t;



typedef struct {
    uint32_t            id;
    stich_frame_kind_t  kind;
    stich_frame_state_t state;
    uint64_t            timestamp_us;
    uint32_t            source;
    uint32_t            schema;
    uint8_t             payload[STICH_PAYLOAD_MAX];
    size_t              payload_len;
} stich_frame_t;


static inline void stich_frame_init(stich_frame_t *frm){
    uint8_t *ptr = (uint8_t *)frm;
    for(size_t i = 0;i <sizeof(*frm);i++){
        ptr[i] = 0;
    }
}


#endif