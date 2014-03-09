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

TEST(TestMatrixSetElement, SomeRandomElementsInMatrix3x4)
{
    Matrix<int> matrix(2, 3);
    matrix.setElement(4, 1, 1);
    EXPECT_EQ(4, matrix.elements_.at(1).at(1));
    matrix.setElement(10, 0, 1);
    EXPECT_EQ(10, matrix.elements_.at(0).at(1));
    EXPECT_EQ(0, matrix.elements_.at(0).at(0));
    EXPECT_EQ(0, matrix.elements_.at(0).at(2));
    EXPECT_EQ(0, matrix.elements_.at(1).at(0));
    EXPECT_EQ(0, matrix.elements_.at(1).at(2));
}

TEST(TestMatrixGetElement, SomeRandomElementsInMatrix3x4)
{
    Matrix<int> matrix(2, 3);
    matrix.setElement(4, 1, 1);
    EXPECT_EQ(4, matrix.getElement(1, 1));
    matrix.setElement(10, 0, 1);
    EXPECT_EQ(10, matrix.getElement(0, 1));
    EXPECT_EQ(0, matrix.getElement(0, 0));
    EXPECT_EQ(0, matrix.getElement(0, 2));
    EXPECT_EQ(0, matrix.getElement(1, 0));
    EXPECT_EQ(0, matrix.getElement(1, 2));
}

TEST(TestMatrixSetColumnsNumber, set3ColumnsForMatrix2x2)
{
    Matrix<int> matrix(2, 2);
    matrix.setColumnsNumber(3);
    EXPECT_EQ(3, matrix.elements_.at(0).size());
    EXPECT_EQ(3, matrix.elements_.at(1).size());
    EXPECT_EQ(2, matrix.elements_.size());
}

TEST(TestMatrixSetColumnsNumber, set3ColumnsForMatrix2x2WithNotZeroElements)
{
    Matrix<int> matrix(2, 2);
    matrix.setElement(31, 0, 0);
    matrix.setElement(25, 0, 1);
    matrix.setElement(67, 1, 0);
    matrix.setElement(1, 1, 1);
    EXPECT_EQ(2,  matrix.getColumnsNumber());
    EXPECT_EQ(2,  matrix.getRowsNumber());
    matrix.setColumnsNumber(3);
    EXPECT_EQ(3,  matrix.getColumnsNumber());
    EXPECT_EQ(2,  matrix.getRowsNumber());
    EXPECT_EQ(3,  matrix.elements_.at(0).size());
    EXPECT_EQ(3,  matrix.elements_.at(1).size());
    EXPECT_EQ(2,  matrix.elements_.size());
    EXPECT_EQ(31, matrix.getElement(0, 0));
    EXPECT_EQ(25, matrix.getElement(0, 1));
    EXPECT_EQ(0,  matrix.getElement(0, 2));
    EXPECT_EQ(67, matrix.getElement(1, 0));
    EXPECT_EQ(1,  matrix.getElement(1, 1));
    EXPECT_EQ(0,  matrix.getElement(1, 2));
}

TEST(TestMatrixGetElementsToCopyFromVector, AllCases)
{
    Matrix<int> matrix(4, 4);
    std::vector<int> test_vector(5, 7);
    std::vector<int>::iterator test_vector_iterator = test_vector.begin();
    EXPECT_EQ(4, 
              matrix.getNumberOfElementsToCopyFromVector(test_vector_iterator, 
                                                         test_vector.end()));
    test_vector_iterator += matrix.getColumnsNumber();
    EXPECT_EQ(1, 
              matrix.getNumberOfElementsToCopyFromVector(test_vector_iterator, 
                                                         test_vector.end()));
}

TEST(TestMatrixSetElementsFromVector, VectorWith5Elements)
{
    Matrix<int> matrix(3, 3);
    std::vector<int> test_vector(5, 7);
    matrix.setElementsFromVector(test_vector);
    EXPECT_EQ(7, matrix.getElement(0, 0));
    EXPECT_EQ(7, matrix.getElement(0, 1));
    EXPECT_EQ(7, matrix.getElement(0, 2));
    EXPECT_EQ(7, matrix.getElement(1, 0));
    EXPECT_EQ(7, matrix.getElement(1, 1));
    EXPECT_EQ(0, matrix.getElement(1, 2));
    EXPECT_EQ(0, matrix.getElement(2, 0));
    EXPECT_EQ(0, matrix.getElement(2, 1));
    EXPECT_EQ(0, matrix.getElement(2, 2));
}
