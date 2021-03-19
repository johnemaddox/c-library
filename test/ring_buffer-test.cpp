#include "gtest/gtest.h"
#include "ring_buffer.h"

namespace
{

TEST(RingBufferInit, FlagOk)
{
    uint8_t buf[8];
    rb_handle_t rb;
    ASSERT_EQ(rb_init(&rb, buf, 8), RB_OK);
}

TEST(RingBufferInit, FlagLenSize)
{
    uint8_t buf[9];
    rb_handle_t rb;
    ASSERT_EQ(rb_init(&rb, buf, 9), RB_LEN_SIZE);
}

TEST(RingBufferInit, FlagLenMismatch)
{
    uint8_t buf[8];
    rb_handle_t rb;
    ASSERT_EQ(rb_init(&rb, buf, 16), RB_LEN_MISMATCH);
}

class RingBufferDataStore : public ::testing::Test
{

public:
    rb_handle_t rb;
    rb_error_t rb_error;
    const size_t buf_len = 8;

private:
    void SetUp() override
    {
        uint8_t buf[buf_len];
        rb_error = rb_init(&rb, buf, buf_len);
    }

    void TearDown() override
    {

    }
};

TEST_F(RingBufferDataStore, CycleBuffer)
{
    // TODO: test buffer data cycle
    ASSERT_EQ(rb_error, RB_OK);
}

TEST_F(RingBufferDataStore, FillBuffer)
{
    // TODO: test buffer full
    ASSERT_EQ(rb_error, RB_OK);
}

} /* namespace */
