#include <gtest/gtest.h>
#include "sources/ClassicDeterminantCalculator.h"

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
