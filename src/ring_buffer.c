/*H************************************************************
 *
 * FiFo Ring Buffer
 *
 * @author John E Maddox
 *
*************************************************************H*/

#include "ring_buffer.h"

rb_error_t rb_init (rb_handle_t *handle, uint8_t *buf, size_t buf_len)
{
    rb_error_t err = RB_OK;

    // TODO: is buf_len power of 2?

    // TODO: validate size of buf with buf_len, should match

    handle->p_buf = buf;
    handle->buf_len = buf_len;
    rb_reset(handle);

    return err;
}

size_t rb_put (rb_handle_t *handle, uint8_t data_in)
{
    // TODO: add data to buffer
}

uint8_t rb_get (rb_handle_t *handle)
{
    // TODO: get data from buffer
}

size_t rb_get_space (rb_handle_t *handle)
{
    // TODO: get remaining space
}

void rb_reset (rb_handle_t *handle)
{
    handle->head_idx = 0;
    handle->tail_idx = 0;
}
