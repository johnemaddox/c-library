/*H************************************************************
 *
 * FiFo Ring Buffer
 *
 * @author John E Maddox
 *
*************************************************************H*/

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#ifdef __cplusplus
    extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

typedef enum
{
    RB_OK,
    RB_LEN_SIZE,
    RB_LEN_MISMATCH

} rb_error_t;

typedef struct
{
    uint8_t *p_buf;
    size_t   buf_len;
    size_t   head_idx;
    size_t   tail_idx;

} rb_handle_t;

/*  configures handle and validates buffer and buffer length
 *  - buffer needs to match buffer length
 *  - buffer length must be a power of 2
 *  - one space is reserved, actual usable length is n-1
 */
rb_error_t rb_init (rb_handle_t *handle, uint8_t *buf, size_t buf_len);

// returns remaining buffer space
size_t rb_put (rb_handle_t *handle, uint8_t data_in);

uint8_t rb_get (rb_handle_t *handle);

// returns remaining buffer space
size_t rb_get_space (rb_handle_t *handle);

// zeros out buffer indexes
void rb_reset (rb_handle_t *handle);

#ifdef __cplusplus
    }
#endif
#endif /* RING_BUFFER_H */
