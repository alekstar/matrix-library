#include <gtest/gtest.h>
#include "../sources/Matrix.h"
#include <vector>

TEST(TestMatrixConstructor, DefaultConstructor)
{
    Matrix<int> matrix;
    EXPECT_EQ(0, matrix.elements_.size());
}

TEST(TestMatrixConstructor, DefaultMatrix1x1)
{
    Matrix<int> matrix(1, 1);
    EXPECT_EQ(1, matrix.elements_.size());
    EXPECT_EQ(1, matrix.elements_.at(0).size());
    EXPECT_EQ(0, matrix.elements_.at(0).at(0));
}

TEST(TestMatrixConstructor, DefaultMatrix2x2)
{
    Matrix<int> matrix(2, 2);
    EXPECT_EQ(2, matrix.elements_.size());
    EXPECT_EQ(2, matrix.elements_.at(0).size());
    EXPECT_EQ(2, matrix.elements_.at(1).size());
    EXPECT_EQ(0, matrix.elements_.at(0).at(0));
    EXPECT_EQ(0, matrix.elements_.at(0).at(1));
    EXPECT_EQ(0, matrix.elements_.at(1).at(0));
    EXPECT_EQ(0, matrix.elements_.at(1).at(1));
}

TEST(TestMatrixSetRowsNumber, set3RowsForNewMatrix)
{
    Matrix<int> matrix;
    matrix.setRowsNumber(3);
    EXPECT_EQ(3, matrix.elements_.size());
    EXPECT_EQ(0, matrix.elements_.at(0).size());
    EXPECT_EQ(0, matrix.elements_.at(1).size());
    EXPECT_EQ(0, matrix.elements_.at(2).size());
}

TEST(TestMatrixIsElementIndexInRange, TestCase)
{
    Matrix<int> matrix(2, 3);
    EXPECT_TRUE(matrix.isElementIndexInRange(0, 0));
    EXPECT_TRUE(matrix.isElementIndexInRange(1, 2));
    EXPECT_FALSE(matrix.isElementIndexInRange(-1, -2));
    EXPECT_FALSE(matrix.isElementIndexInRange(2, 3));
    EXPECT_FALSE(matrix.isElementIndexInRange(3, 2));
    EXPECT_FALSE(matrix.isElementIndexInRange(1, 5));
}
