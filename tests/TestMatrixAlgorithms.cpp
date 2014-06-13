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

TEST(Transpose, Matrix4x4)
{
    Matrix<int> matrix(4, 4);
    matrix.at(0, 0) = 1;
    matrix.at(0, 1) = 11;
    matrix.at(0, 2) = 185;
    matrix.at(0, 3) = 13;
    matrix.at(1, 0) = 5;
    matrix.at(1, 1) = 12;
    matrix.at(1, 2) = 9;
    matrix.at(1, 3) = 26;
    matrix.at(2, 0) = 6;
    matrix.at(2, 1) = 9;
    matrix.at(2, 2) = 19;
    matrix.at(2, 3) = 21;
    matrix.at(3, 0) = 10;
    matrix.at(3, 1) = 14;
    matrix.at(3, 2) = 13;
    matrix.at(3, 3) = 2;
    Matrix<int> result = transpose(matrix);
    EXPECT_EQ(matrix.getColumnsNumber(),    result.getRowsNumber());
    EXPECT_EQ(matrix.getRowsNumber(),       result.getColumnsNumber());
    EXPECT_EQ(matrix.at(0, 0), result.at(0, 0));
    EXPECT_EQ(matrix.at(0, 1), result.at(1, 0));
    EXPECT_EQ(matrix.at(0, 2), result.at(2, 0));
    EXPECT_EQ(matrix.at(0, 3), result.at(3, 0));
    EXPECT_EQ(matrix.at(1, 0), result.at(0, 1));
    EXPECT_EQ(matrix.at(1, 1), result.at(1, 1));
    EXPECT_EQ(matrix.at(1, 2), result.at(2, 1));
    EXPECT_EQ(matrix.at(1, 3), result.at(3, 1));
    EXPECT_EQ(matrix.at(2, 0), result.at(0, 2));
    EXPECT_EQ(matrix.at(2, 1), result.at(1, 2));
    EXPECT_EQ(matrix.at(2, 2), result.at(2, 2));
    EXPECT_EQ(matrix.at(2, 3), result.at(3, 2));
    EXPECT_EQ(matrix.at(3, 0), result.at(0, 3));
    EXPECT_EQ(matrix.at(3, 1), result.at(1, 3));
    EXPECT_EQ(matrix.at(3, 2), result.at(2, 3));
    EXPECT_EQ(matrix.at(3, 3), result.at(3, 3));

    EXPECT_EQ(1,    result.at(0, 0));
    EXPECT_EQ(5,    result.at(0, 1));
    EXPECT_EQ(6,    result.at(0, 2));
    EXPECT_EQ(10,   result.at(0, 3));
    EXPECT_EQ(11,   result.at(1, 0));
    EXPECT_EQ(12,   result.at(1, 1));
    EXPECT_EQ(9,    result.at(1, 2));
    EXPECT_EQ(14,   result.at(1, 3));
    EXPECT_EQ(185,  result.at(2, 0));
    EXPECT_EQ(9,    result.at(2, 1));
    EXPECT_EQ(19,   result.at(2, 2));
    EXPECT_EQ(13,   result.at(2, 3));
    EXPECT_EQ(13,   result.at(3, 0));
    EXPECT_EQ(26,   result.at(3, 1));
    EXPECT_EQ(21,   result.at(3, 2));
    EXPECT_EQ(2,    result.at(3, 3));
}

TEST(Transpose, DeterminantsMustBeEqual)
{
    Matrix<int> matrix(4, 4);
    matrix.at(0, 0) = 1;
    matrix.at(0, 1) = 11;
    matrix.at(0, 2) = 185;
    matrix.at(0, 3) = 13;
    matrix.at(1, 0) = 5;
    matrix.at(1, 1) = 12;
    matrix.at(1, 2) = 9;
    matrix.at(1, 3) = 26;
    matrix.at(2, 0) = 6;
    matrix.at(2, 1) = 9;
    matrix.at(2, 2) = 19;
    matrix.at(2, 3) = 21;
    matrix.at(3, 0) = 10;
    matrix.at(3, 1) = 14;
    matrix.at(3, 2) = 13;
    matrix.at(3, 3) = 2;
    
    Matrix<int> result = transpose(matrix);
    
    EXPECT_DOUBLE_EQ(calculateDeterminant(matrix),
                     calculateDeterminant(result));
}

// Transposed multiplication of matrices must be equal to multiplication
// of transposed matrices in reversed order
TEST(Transpose, TransposedMultiplicationOfMatrices)
{
    Matrix<int> matrix1(4, 4);
    matrix1.at(0, 0) = 1;
    matrix1.at(0, 1) = 11;
    matrix1.at(0, 2) = 185;
    matrix1.at(0, 3) = 13;
    matrix1.at(1, 0) = 5;
    matrix1.at(1, 1) = 12;
    matrix1.at(1, 2) = 9;
    matrix1.at(1, 3) = 26;
    matrix1.at(2, 0) = 6;
    matrix1.at(2, 1) = 9;
    matrix1.at(2, 2) = 19;
    matrix1.at(2, 3) = 21;
    matrix1.at(3, 0) = 10;
    matrix1.at(3, 1) = 14;
    matrix1.at(3, 2) = 13;
    matrix1.at(3, 3) = 2;
    
    
    Matrix<int> matrix2(4, 4);
    matrix2.at(0, 0) = 1;
    matrix2.at(0, 1) = 2;
    matrix2.at(0, 2) = 3;
    matrix2.at(0, 3) = 4;
    matrix2.at(1, 0) = 5;
    matrix2.at(1, 1) = 6;
    matrix2.at(1, 2) = 7;
    matrix2.at(1, 3) = 8;
    matrix2.at(2, 0) = 9;
    matrix2.at(2, 1) = 10;
    matrix2.at(2, 2) = 11;
    matrix2.at(2, 3) = 12;
    matrix2.at(3, 0) = 13;
    matrix2.at(3, 1) = 14;
    matrix2.at(3, 2) = 15;
    matrix2.at(3, 3) = 16;
    
    Matrix<int> multiplication_of_matrices = matrix1 * matrix2;
    Matrix<int> reversed_multiplication_of_tranposed_matrices = 
        transpose(matrix2)* transpose(matrix1);
    Matrix<int> transposed_multiplication_of_matrices = 
        transpose(multiplication_of_matrices);
    EXPECT_TRUE(reversed_multiplication_of_tranposed_matrices == 
                transposed_multiplication_of_matrices);
}

TEST(Transpose, DoubleTransposedMustBeEqualToOriginal)
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
    
    Matrix<double> double_transposed_matrix = transpose(transpose(matrix));
    EXPECT_TRUE(matrix == double_transposed_matrix);
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

