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

TEST(GetMinor, Minor0x0FromMatrix3x3)
{
    Matrix<int> matrix3x3(3, 3);
    matrix3x3.at(0, 0) = 1;
    matrix3x3.at(0, 1) = 2;
    matrix3x3.at(0, 2) = 3;
    matrix3x3.at(1, 0) = 4;
    matrix3x3.at(1, 1) = 5;
    matrix3x3.at(1, 2) = 6;
    matrix3x3.at(2, 0) = 7;
    matrix3x3.at(2, 1) = 8;
    matrix3x3.at(2, 2) = 9;
    
    Matrix<int> minor_for_0x0 = 
        ClassicDeterminantCalculator().getMinorForElement(matrix3x3, 0, 0);
    
    EXPECT_EQ(2, minor_for_0x0.getRowsNumber());
    EXPECT_EQ(2, minor_for_0x0.getColumnsNumber());
    EXPECT_EQ(5, minor_for_0x0.at(0, 0));
    EXPECT_EQ(6, minor_for_0x0.at(0, 1));
    EXPECT_EQ(8, minor_for_0x0.at(1, 0));
    EXPECT_EQ(9, minor_for_0x0.at(1, 1));
}

TEST(GetMinor, Minor1x1FromMatrix3x3)
{
    Matrix<int> matrix3x3(3, 3);
    matrix3x3.at(0, 0) = 1;
    matrix3x3.at(0, 1) = 2;
    matrix3x3.at(0, 2) = 3;
    matrix3x3.at(1, 0) = 4;
    matrix3x3.at(1, 1) = 5;
    matrix3x3.at(1, 2) = 6;
    matrix3x3.at(2, 0) = 7;
    matrix3x3.at(2, 1) = 8;
    matrix3x3.at(2, 2) = 9;
    
    Matrix<int> minor_for_1x1 = 
        ClassicDeterminantCalculator().getMinorForElement(matrix3x3, 1, 1);
    
    EXPECT_EQ(1, minor_for_1x1.at(0, 0));
    EXPECT_EQ(3, minor_for_1x1.at(0, 1));
    EXPECT_EQ(7, minor_for_1x1.at(1, 0));
    EXPECT_EQ(9, minor_for_1x1.at(1, 1));
}

TEST(GetMinor, Minor0x1FromMatrix3x3)
{
    Matrix<int> matrix3x3(3, 3);
    matrix3x3.at(0, 0) = 1;
    matrix3x3.at(0, 1) = 2;
    matrix3x3.at(0, 2) = 3;
    matrix3x3.at(1, 0) = 4;
    matrix3x3.at(1, 1) = 5;
    matrix3x3.at(1, 2) = 6;
    matrix3x3.at(2, 0) = 7;
    matrix3x3.at(2, 1) = 8;
    matrix3x3.at(2, 2) = 9;
    
    Matrix<int> minor_for_0x1 = 
        ClassicDeterminantCalculator().getMinorForElement(matrix3x3, 0, 1);
    
    EXPECT_EQ(4, minor_for_0x1.at(0, 0));
    EXPECT_EQ(6, minor_for_0x1.at(0, 1));
    EXPECT_EQ(7, minor_for_0x1.at(1, 0));
    EXPECT_EQ(9, minor_for_0x1.at(1, 1));
}

