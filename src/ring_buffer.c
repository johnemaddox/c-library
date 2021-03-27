/*H************************************************************
 *
 * FiFo Ring Buffer
 *
 *  Performs basic FiFo operations for use in embedded systems.
 *  Maintains thread safe operations by using an empty buffer
 *  cell as a way to to prevent simultneous read and writes to
 *  the same buffer location. Each cell utilizes one byte.
 *
 *  Length is required to be a power of two, if it is not memory
 *  will not be allocated and RB_LEN_SIZE will be returned. This
 *  will result in seg fault if the wrong size buffer is created
 *  and the flag is not checked.
 *
 * @author John E Maddox
 *
*************************************************************H*/

#include "ring_buffer.h"
#include <stdbool.h>
#include <stdlib.h>

static bool is_power_of_two (size_t num)
{
    if (num == 0) { return false; }
    if ((num & (num - 1)) != 0) { return false; }
    return true;
}

static size_t get_next_idx (size_t idx, size_t max)
{
    return ((idx + 1) & (max - 1));
}

rb_status_t rb_init (rb_handle_t **rb, size_t max_len)
{
    if (!is_power_of_two(max_len)) { return RB_LEN_SIZE; }

    (*rb) = (rb_handle_t*)malloc(sizeof(rb_handle_t));

    (*rb)->data = (uint8_t*)calloc(max_len, sizeof(uint8_t));
    (*rb)->max_len = max_len;
    rb_reset(*rb);

    return RB_OK;
}

rb_status_t rb_put (rb_handle_t *rb, uint8_t data_in)
{
    size_t next_idx = get_next_idx(rb->head_idx, rb->max_len);

    if (next_idx == rb->tail_idx) { return RB_FULL; }

    rb->data[rb->head_idx] = data_in;

    rb->head_idx = next_idx;

    return RB_OK;
}

rb_status_t rb_get (rb_handle_t *rb, uint8_t *data_out)
{
    if (rb->head_idx == rb->tail_idx) { return RB_EMPTY; }

    *data_out = rb->data[rb->tail_idx];

    rb->tail_idx = get_next_idx(rb->tail_idx, rb->max_len);

    return RB_OK;
}

void rb_reset (rb_handle_t *rb)
{
    rb->head_idx = 0;
    rb->tail_idx = 0;
}

void rb_free (rb_handle_t** rb)
{
    free((*rb)->data);
    (*rb)->data = NULL;

    free(*rb);
    *rb = NULL;
}
