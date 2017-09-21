#include "gtest/gtest.h"
#include "gmock/gmock.h"

// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md

// Simple test, does not use gmock
TEST(Dummy, foobar)
{
    EXPECT_EQ(1, 1);
}

TEST(Dummy2, foobar)
{
    EXPECT_LE(5, 2) << "Is 5 less than 2?\n";
}

TEST(AssertTest, foobar)
{
    EXPECT_LE(5, 2) << "5 is not less than 2, but we continue\n";
    ASSERT_LT(5, 2) << "This is with assert, execution stops here\n";
    EXPECT_LE(5, 2) << "This is not executed\n";
}
