#include <gtest/gtest.h>
#include "sources/AreAlmostEqual.h"

TEST(AreAlmostEqual, ShouldReturnTrueIfTwoOperandsAreExactlyEqual)
{
    double operand1 = 1.0;
    double operand2 = 1.0;
    EXPECT_TRUE(areAlmostEqual(operand1, 
                               operand2, 
                               EPSILON_FOR_DOUBLE_COMPARISON));
}

TEST(AreAlmostEqual, ShouldReturnFalseIfTwoOperandsAreExactlyNotEqual)
{
    double operand1 = 2.0;
    double operand2 = 1.0;
    EXPECT_FALSE(areAlmostEqual(operand1, 
                                operand2, 
                                EPSILON_FOR_DOUBLE_COMPARISON));
}

TEST(AreAlmostEqual, ShouldReturnTrueIfTwoOperandsAreAlmostEqualCase1)
{
    double operand1 = 1.000009;
    double operand2 = 1.0;
    EXPECT_TRUE(areAlmostEqual(operand1, 
                               operand2, 
                               EPSILON_FOR_DOUBLE_COMPARISON));
}

TEST(AreAlmostEqual, ShouldReturnTrueIfTwoOperandsAreAlmostEqualCase2)
{
    double operand1 = 1.000009;
    double operand2 = 1.000008;
    EXPECT_TRUE(areAlmostEqual(operand1, 
                               operand2, 
                               EPSILON_FOR_DOUBLE_COMPARISON));
}

TEST(AreAlmostEqual, ShouldReturnFalseIfOneOfOperandsHigherByEpsilon)
{
    double operand1 = 1.000018;
    double operand2 = 1.000008;
    EXPECT_FALSE(areAlmostEqual(operand1, 
                                operand2, 
                                EPSILON_FOR_DOUBLE_COMPARISON));
}

TEST(AreAlmostEqual, ShouldReturnTrueIfTwoOperandsAreAlmostEqualCase3)
{
    double operand1 = 1.000017;
    double operand2 = 1.000008;
    EXPECT_TRUE(areAlmostEqual(operand1, 
                               operand2, 
                               EPSILON_FOR_DOUBLE_COMPARISON));
}
