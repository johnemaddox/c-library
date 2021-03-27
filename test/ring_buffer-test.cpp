#include "gtest/gtest.h"
#include "ring_buffer.h"

namespace
{

TEST(RingBufferInit, FlagOk)
{
    rb_handle_t *rb;
    ASSERT_EQ(rb_init(&rb, 8), RB_OK);
    rb_free(&rb);
}

TEST(RingBufferInit, FlagLenSize)
{
    rb_handle_t *rb;
    ASSERT_EQ(rb_init(&rb, 9), RB_LEN_SIZE);
    // NOTE: memory is not allocated when this flag is returned.
}

class RingBufferDataStore : public ::testing::Test
{

public:
    rb_handle_t *rb;
    const size_t max_len = 8;
    uint8_t data_out;

private:
    void SetUp() override
    {
        ASSERT_EQ(rb_init(&rb, max_len), RB_OK);
    }

    void TearDown() override
    {
        rb_free(&rb);
    }
};

TEST_F(RingBufferDataStore, FillBuffer)
{
    for (int i=0; i < max_len-1; i++)
    {
        EXPECT_EQ(rb_put(rb, i), RB_OK);
    }
    EXPECT_EQ(rb_put(rb, 0xFFU), RB_FULL);
}

TEST_F(RingBufferDataStore, CycleBuffer)
{
    size_t two_buffer_cycles = (max_len)*2;
    for (int i=0; i < two_buffer_cycles; i++)
    {
        EXPECT_EQ(rb_put(rb, i), RB_OK);

        EXPECT_EQ(rb_get(rb, &data_out), RB_OK);
        EXPECT_EQ(data_out, i);
    }
}

TEST_F(RingBufferDataStore, ResetBuffer)
{
    EXPECT_EQ(rb_put(rb, 0xFFU), RB_OK);

    rb_reset(rb);
    EXPECT_EQ(rb_get(rb, &data_out), RB_EMPTY);
}

} /* namespace */
