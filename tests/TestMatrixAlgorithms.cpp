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
