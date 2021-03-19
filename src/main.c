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
    printf("Ring Buffer");

    const size_t buf_len = 9;
    uint8_t buf[8];
    rb_handle_t rb;

    if (rb_init(&rb, buf, 8) == RB_OK)
    {
        // TODO: Fill buffer
        printf("Fill Buffer");
    }

    return 0;
}
