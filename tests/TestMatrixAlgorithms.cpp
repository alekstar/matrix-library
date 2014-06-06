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

TEST(CalculateDeterminantViaTriangularMatrix, Matrix4x4)
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
                     calculateDeterminantViaTriangularMatrix(matrix));
}

TEST(Transpose, Matrix1x2)
{
    Matrix<int> matrix(1, 2);
    matrix.at(0, 0) = 1;
    matrix.at(0, 1) = 2;
    Matrix<int> result = transpose(matrix);
    EXPECT_EQ(matrix.getColumnsNumber(),    result.getRowsNumber());
    EXPECT_EQ(matrix.getRowsNumber(),       result.getColumnsNumber());
    EXPECT_EQ(matrix.at(0, 0), result.at(0, 0));
    EXPECT_EQ(matrix.at(0, 1), result.at(1, 0));
}

TEST(Transpose, Matrix2x2)
{
    Matrix<int> matrix(2, 2);
    matrix.at(0, 0) = 1;
    matrix.at(0, 1) = 2;
    matrix.at(1, 0) = 3;
    matrix.at(1, 1) = 4;
    Matrix<int> result = transpose(matrix);
    EXPECT_EQ(matrix.getColumnsNumber(),    result.getRowsNumber());
    EXPECT_EQ(matrix.getRowsNumber(),       result.getColumnsNumber());
    EXPECT_EQ(matrix.at(0, 0), result.at(0, 0));
    EXPECT_EQ(matrix.at(0, 1), result.at(1, 0));
    EXPECT_EQ(matrix.at(1, 0), result.at(0, 1));
    EXPECT_EQ(matrix.at(1, 1), result.at(1, 1));
}
