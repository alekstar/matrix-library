#include <gtest/gtest.h>
#include "../sources/Matrix.h"
#include <vector>
#include <string>

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

TEST(TestMatrixSetElementsFromVector, VectorWithMoreElementsThanInMatrix)
{
    Matrix<int> matrix(3, 3);
    std::vector<int> test_vector(10, 3);
    matrix.setElementsFromVector(test_vector);
    EXPECT_EQ(3, matrix.getElement(0, 0));
    EXPECT_EQ(3, matrix.getElement(0, 1));
    EXPECT_EQ(3, matrix.getElement(0, 2));
    EXPECT_EQ(3, matrix.getElement(1, 0));
    EXPECT_EQ(3, matrix.getElement(1, 1));
    EXPECT_EQ(3, matrix.getElement(1, 2));
    EXPECT_EQ(3, matrix.getElement(2, 0));
    EXPECT_EQ(3, matrix.getElement(2, 1));
    EXPECT_EQ(3, matrix.getElement(2, 2));
}

TEST(TestMatrixPutToStreamOperator, MatrixWithFiveSevens)
{
    Matrix<int> matrix(3, 3);
    std::vector<int> test_vector(5, 7);
    matrix.setElementsFromVector(test_vector);
    std::stringstream matrix_stringstream;
    matrix_stringstream << matrix;
    std::string actual_matrix_string;
    actual_matrix_string = matrix_stringstream.str();
    std::string expected_matrix_string = "7\t7\t7\t\n7\t7\t0\t\n0\t0\t0\t\n";
    EXPECT_EQ(actual_matrix_string, expected_matrix_string);
}

TEST(TestMatrixPutToStreamOperator, Matrix0x0)
{
    Matrix<int> matrix(0, 0);
    std::stringstream matrix_stringstream;
    matrix_stringstream << matrix;
    std::string actual_matrix_string;
    actual_matrix_string = matrix_stringstream.str();
    std::string expected_matrix_string = "";
    EXPECT_EQ(actual_matrix_string, expected_matrix_string);
}

TEST(MatrixConstructor, ConstructorFromVectorWithMatrix0x0)
{
    std::vector<int> test_vector(10, 3);
    Matrix<int> matrix(0, 0, test_vector);
    EXPECT_EQ(0, matrix.getRowsNumber());
    EXPECT_EQ(0, matrix.getColumnsNumber());
}

TEST(MatrixConstructor, ConstructorFromVectorWithMatrix2x2)
{
    std::vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    Matrix<int> matrix(2, 2, values);
    EXPECT_EQ(1, matrix.getElement(0, 0));
    EXPECT_EQ(2, matrix.getElement(0, 1));
    EXPECT_EQ(3, matrix.getElement(1, 0));
    EXPECT_EQ(4, matrix.getElement(1, 1));
}

TEST(MatrixMultiplyWithOneValue, ValueIs2)
{
    std::vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    Matrix<int> matrix(2, 2, values);
    matrix = matrix * 2;
    EXPECT_EQ(2, matrix.getElement(0, 0));
    EXPECT_EQ(4, matrix.getElement(0, 1));
    EXPECT_EQ(6, matrix.getElement(1, 0));
    EXPECT_EQ(8, matrix.getElement(1, 1));
}

TEST(MatrixMultiplyWithOneValue, ValueIsOneAndHalf)
{
    std::vector<double> values;
    values.push_back(1.0);
    values.push_back(2.0);
    values.push_back(3.0);
    values.push_back(4.0);
    Matrix<double> matrix(2, 2, values);
    matrix = matrix * 1.5;
    EXPECT_EQ(1.5,  matrix.getElement(0, 0));
    EXPECT_EQ(3,    matrix.getElement(0, 1));
    EXPECT_EQ(4.5,  matrix.getElement(1, 0));
    EXPECT_EQ(6,    matrix.getElement(1, 1));
}

TEST(MatrixIsMultiplyPossible, AllCasesWithVector)
{
    Matrix<int> matrix2x2(2, 2);
    std::vector<int> vector_with_size2(2);
    std::vector<int> vector_with_size3(3);
    EXPECT_TRUE(matrix2x2.isMultiplyPossibleWith(vector_with_size2));
    EXPECT_FALSE(matrix2x2.isMultiplyPossibleWith(vector_with_size3));
}

TEST(MatrixConstructor, ConstructorFromVectorOf5Elements)
{
    std::vector<int> test_vector;
    test_vector.push_back(1);
    test_vector.push_back(15);
    test_vector.push_back(-23);
    test_vector.push_back(0);
    test_vector.push_back(-1);
    Matrix<int> matrix(test_vector);
    EXPECT_EQ(1, matrix.getColumnsNumber());
    EXPECT_EQ(5, matrix.getRowsNumber());
    EXPECT_EQ(1, matrix.getElement(0, 0));
    EXPECT_EQ(15, matrix.getElement(1, 0));
    EXPECT_EQ(-23, matrix.getElement(2, 0));
    EXPECT_EQ(0, matrix.getElement(3, 0));
    EXPECT_EQ(-1, matrix.getElement(4, 0));
    std::stringstream matrix_stringstream;
    matrix_stringstream << matrix;
    std::string actual_matrix_string;
    actual_matrix_string = matrix_stringstream.str();
    std::string expected_matrix_string = 
        "1\t\n15\t\n-23\t\n0\t\n-1\t\n";
    EXPECT_EQ(expected_matrix_string, actual_matrix_string);
}
