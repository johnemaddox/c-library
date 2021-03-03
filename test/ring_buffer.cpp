#include "gtest/gtest.h"
#include "ring_buffer.h"

TEST(ring_buffer, rb_init) {
    EXPECT_EQ (rb_init(), 1);
}
