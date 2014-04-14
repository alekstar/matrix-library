#include <gtest/gtest.h>
#include "sources/ClassicDeterminantCalculator.h"

TEST(DefineSignForElement, SeveralCases)
{
    ClassicDeterminantCalculator calculator;
    EXPECT_EQ(1,  calculator.defineSignForElement(0, 0));
    EXPECT_EQ(-1, calculator.defineSignForElement(0, 1));
    EXPECT_EQ(1,  calculator.defineSignForElement(0, 2));
    EXPECT_EQ(-1, calculator.defineSignForElement(1, 0));
    EXPECT_EQ(1,  calculator.defineSignForElement(1, 1));
    EXPECT_EQ(-1, calculator.defineSignForElement(1, 2));
    EXPECT_EQ(1,  calculator.defineSignForElement(2, 0));
    EXPECT_EQ(-1, calculator.defineSignForElement(2, 1));
    EXPECT_EQ(1,  calculator.defineSignForElement(2, 2));
}
