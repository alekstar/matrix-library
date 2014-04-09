#include <gtest/gtest.h>
#include <vector>
#include "../sources/Matrix.h"
#include "../sources/exceptions/MatrixIsNotSquare.h"
#include "../sources/MatrixAlgorithms.h"


using namespace MatrixAlgorithms;

TEST(HaveZeroRows, MatrixWithoutZeroRows)
{
    Matrix<double> matrix(3, 3);
    matrix.setElement(0.0, 0, 0);
    matrix.setElement(0.1, 0, 1);
    matrix.setElement(0.2, 0, 2);
    matrix.setElement(1.0, 1, 0);
    matrix.setElement(1.1, 1, 1);
    matrix.setElement(1.2, 1, 2);
    matrix.setElement(2.0, 2, 0);
    matrix.setElement(2.1, 2, 1);
    matrix.setElement(2.2, 2, 2);
    EXPECT_FALSE(haveZeroRows(matrix));
}

TEST(HaveZeroRows, MatrixWithOneZeroRow)
{
    Matrix<double> matrix(3, 3);
    matrix.setElement(0.0, 0, 0);
    matrix.setElement(0.1, 0, 1);
    matrix.setElement(0.2, 0, 2);
    matrix.setElement(1.0, 1, 0);
    matrix.setElement(1.1, 1, 1);
    matrix.setElement(1.2, 1, 2);
    matrix.setElement(0.0, 2, 0);
    matrix.setElement(0.0, 2, 1);
    matrix.setElement(0.0, 2, 2);
    EXPECT_TRUE(haveZeroRows(matrix));
}

TEST(HaveZeroRows, MatrixWithSeveralZeroRows)
{
    Matrix<double> matrix(3, 3);
    matrix.setElement(0.0, 0, 0);
    matrix.setElement(0.0, 0, 1);
    matrix.setElement(0.0, 0, 2);
    matrix.setElement(1.0, 1, 0);
    matrix.setElement(1.1, 1, 1);
    matrix.setElement(1.2, 1, 2);
    matrix.setElement(0.0, 2, 0);
    matrix.setElement(0.0, 2, 1);
    matrix.setElement(0.0, 2, 2);
    EXPECT_TRUE(haveZeroRows(matrix));
}

TEST(HaveZeroColumns, MatrixWithoutZeroColumns)
{
    Matrix<double> matrix(3, 3);
    matrix.setElement(0.0, 0, 0);
    matrix.setElement(0.1, 0, 1);
    matrix.setElement(0.2, 0, 2);
    matrix.setElement(1.0, 1, 0);
    matrix.setElement(1.1, 1, 1);
    matrix.setElement(1.2, 1, 2);
    matrix.setElement(2.0, 2, 0);
    matrix.setElement(2.1, 2, 1);
    matrix.setElement(2.2, 2, 2);
    EXPECT_FALSE(haveZeroColumns(matrix));
}

TEST(HaveZeroColumns, MatrixWithOneZeroColumn)
{
    Matrix<double> matrix(3, 3);
    matrix.setElement(0.0, 0, 0);
    matrix.setElement(0.1, 0, 1);
    matrix.setElement(0.2, 0, 2);
    matrix.setElement(0.0, 1, 0);
    matrix.setElement(1.1, 1, 1);
    matrix.setElement(1.2, 1, 2);
    matrix.setElement(0.0, 2, 0);
    matrix.setElement(2.1, 2, 1);
    matrix.setElement(2.2, 2, 2);
    EXPECT_TRUE(haveZeroColumns(matrix));
}

TEST(HaveZeroColumns, MatrixWithSeveralZeroColumns)
{
    Matrix<double> matrix(3, 3);
    matrix.setElement(0.0, 0, 0);
    matrix.setElement(0.0, 0, 1);
    matrix.setElement(0.2, 0, 2);
    matrix.setElement(0.0, 1, 0);
    matrix.setElement(0.0, 1, 1);
    matrix.setElement(1.2, 1, 2);
    matrix.setElement(0.0, 2, 0);
    matrix.setElement(0.0, 2, 1);
    matrix.setElement(2.2, 2, 2);
    EXPECT_TRUE(haveZeroColumns(matrix));
}

TEST(GetUpperTriangularMatrix, Matrix3x3)
{
    Matrix<int> matrix(3, 3);
    matrix.setElement(2,    0, 0);
    matrix.setElement(6,    0, 1);
    matrix.setElement(-1,   0, 2);
    matrix.setElement(0,    1, 0);
    matrix.setElement(2,    1, 1);
    matrix.setElement(1,    1, 2);
    matrix.setElement(2,    2, 0);
    matrix.setElement(-1,   2, 1);
    matrix.setElement(0,    2, 2);
    Matrix<double> upper_triangular_matrix = 
        getUpperTriangularMatrix(matrix);
    EXPECT_DOUBLE_EQ( 2,    upper_triangular_matrix.getElement(0, 0));
    EXPECT_DOUBLE_EQ( 6,    upper_triangular_matrix.getElement(0, 1));
    EXPECT_DOUBLE_EQ(-1,    upper_triangular_matrix.getElement(0, 2));
    EXPECT_DOUBLE_EQ( 0,    upper_triangular_matrix.getElement(1, 0));
    EXPECT_DOUBLE_EQ( 2,    upper_triangular_matrix.getElement(1, 1));
    EXPECT_DOUBLE_EQ( 1,    upper_triangular_matrix.getElement(1, 2));
    EXPECT_DOUBLE_EQ( 0,    upper_triangular_matrix.getElement(2, 0));
    EXPECT_DOUBLE_EQ( 0,    upper_triangular_matrix.getElement(2, 1));
    EXPECT_DOUBLE_EQ( 4.5,  upper_triangular_matrix.getElement(2, 2));
}

TEST(DefineSignForElement, SeveralCases)
{
    EXPECT_EQ(1,  defineSignForElement(0, 0));
    EXPECT_EQ(-1, defineSignForElement(0, 1));
    EXPECT_EQ(1,  defineSignForElement(0, 2));
    EXPECT_EQ(-1, defineSignForElement(1, 0));
    EXPECT_EQ(1,  defineSignForElement(1, 1));
    EXPECT_EQ(-1, defineSignForElement(1, 2));
    EXPECT_EQ(1,  defineSignForElement(2, 0));
    EXPECT_EQ(-1, defineSignForElement(2, 1));
    EXPECT_EQ(1,  defineSignForElement(2, 2));
}
