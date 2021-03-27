/*H************************************************************
 *
 * Main is for Testing purposes only.
 *
 * @author John E Maddox
 *
*************************************************************H*/

#include "ring_buffer.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int main()
{
    printf("Ring Buffer\n");

    const size_t max_len = 8;
    rb_handle_t *rb;

    if (rb_init(&rb, max_len, RB_TYPE_STOP_ON_FULL) == RB_OK)
    {
        uint8_t data_in = 0;
        while (rb_put(rb, data_in) != RB_FULL)
        {
            printf("Data In: %d\n", data_in);
            data_in++;
        }

        uint8_t data_out;
        while (rb_get(rb, &data_out) != RB_EMPTY)
        {
            printf("Data Out: %d\n", data_out);
        }
    }

    rb_free(&rb);

    return 0;
}
