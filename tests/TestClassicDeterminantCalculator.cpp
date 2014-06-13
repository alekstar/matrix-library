#include <gtest/gtest.h>
#include "sources/ClassicDeterminantCalculator.h"

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
        ClassicDeterminantCalculator().getMinorMatrixForElement(matrix3x3, 
                                                                0, 
                                                                0);
    
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
        ClassicDeterminantCalculator().getMinorMatrixForElement(matrix3x3, 
                                                                1, 
                                                                1);
    
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
        ClassicDeterminantCalculator().getMinorMatrixForElement(matrix3x3, 
                                                                0, 
                                                                1);
    
    EXPECT_EQ(4, minor_for_0x1.at(0, 0));
    EXPECT_EQ(6, minor_for_0x1.at(0, 1));
    EXPECT_EQ(7, minor_for_0x1.at(1, 0));
    EXPECT_EQ(9, minor_for_0x1.at(1, 1));
}

TEST(GetMinor, Minor0x0FromMatrix1x1)
{
    Matrix<int> matrix1x1(1, 1, 12);
    Matrix<int> minor_for_0x0 = 
        ClassicDeterminantCalculator().getMinorMatrixForElement(matrix1x1, 
                                                                0, 
                                                                0);
    EXPECT_TRUE(isNull(minor_for_0x0));
}

TEST(GetMinor, Minor0x0FromMatrix0x0)
{
    Matrix<int> matrix0x0;
    EXPECT_THROW(ClassicDeterminantCalculator().
                    getMinorMatrixForElement(matrix0x0, 
                                             0, 
                                             0), RangeError);
}

TEST(GetMinor, Minor1x1FromMatrix2x3)
{
    Matrix<int>matrix2x3(2, 3, 10);
    EXPECT_THROW(ClassicDeterminantCalculator().
                    getMinorMatrixForElement(matrix2x3, 
                                             1, 
                                             1), MatrixIsNotSquare);
}

TEST(CalculateDeterminant, DoubleForMatrix3x3)
{
    Matrix<double> matrix3x3(3, 3);
    matrix3x3.at(0, 0) = 4;
    matrix3x3.at(0, 1) = 3;
    matrix3x3.at(0, 2) = 2;
    matrix3x3.at(1, 0) = 9;
    matrix3x3.at(1, 1) = 1;
    matrix3x3.at(1, 2) = 8;
    matrix3x3.at(2, 0) = 6;
    matrix3x3.at(2, 1) = 5;
    matrix3x3.at(2, 2) = 7;
    
    EXPECT_DOUBLE_EQ(-99, ClassicDeterminantCalculator().calculate(matrix3x3));
}

TEST(CalculateDeterminant, IntegerForMatrix3x3)
{
    Matrix<int> matrix3x3(3, 3);
    matrix3x3.at(0, 0) = 4;
    matrix3x3.at(0, 1) = 3;
    matrix3x3.at(0, 2) = 2;
    matrix3x3.at(1, 0) = 9;
    matrix3x3.at(1, 1) = 1;
    matrix3x3.at(1, 2) = 8;
    matrix3x3.at(2, 0) = 6;
    matrix3x3.at(2, 1) = 5;
    matrix3x3.at(2, 2) = 7;
    
    EXPECT_DOUBLE_EQ(-99, ClassicDeterminantCalculator().calculate(matrix3x3));
}

TEST(CalculateDeterminant, DoubleMatrix4x4)
{
    Matrix<double> matrix(4, 4);
    matrix.setElement(10,       0, 0);
    matrix.setElement(20,       0, 1);
    matrix.setElement(30,       0, 2);
    matrix.setElement(40,       0, 3);
    matrix.setElement(7,        1, 0);
    matrix.setElement(4,        1, 1);
    matrix.setElement(60,       1, 2);
    matrix.setElement(41,       1, 3);
    matrix.setElement(0.5,      2, 0);
    matrix.setElement(0.15,     2, 1);
    matrix.setElement(0.225,    2, 2);
    matrix.setElement(100,      2, 3);
    matrix.setElement(0.001,    3, 0);
    matrix.setElement(20,       3, 1);
    matrix.setElement(4,        3, 2);
    matrix.setElement(8,        3, 3);
    
    EXPECT_DOUBLE_EQ(810037.324, 
                     ClassicDeterminantCalculator().calculate(matrix));
}
