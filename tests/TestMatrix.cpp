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

TEST(MatrixGetRowVector, Matrix0x0)
{
    Matrix<int> matrix;
    vector<int> vector_of_1st_row = matrix.getRowVector(0);
    vector<int> vector_of_2nd_row = matrix.getRowVector(1);
    EXPECT_EQ(0, vector_of_1st_row.size());
    EXPECT_EQ(0, vector_of_2nd_row.size());
}

TEST(MatrixGetRowVector, Matrix1x1)
{
    Matrix<int> matrix(1, 1);
    matrix.setElement(15, 0, 0);
    vector<int> vector_of_1st_row = matrix.getRowVector(0);
    vector<int> vector_of_2nd_row = matrix.getRowVector(1);
    EXPECT_EQ(1, vector_of_1st_row.size());
    EXPECT_EQ(15, vector_of_1st_row.at(0));
    EXPECT_EQ(0, vector_of_2nd_row.size());
}

TEST(MatrixGetRowVector, Matrix2x2)
{
    Matrix<int> matrix(2, 2);
    matrix.setElement(15,   0, 0);
    matrix.setElement(-100, 0, 1);
    matrix.setElement(1,    1, 0);
    matrix.setElement(123,  1, 1);
    vector<int> vector_of_1st_row = matrix.getRowVector(0);
    vector<int> vector_of_2nd_row = matrix.getRowVector(1);
    EXPECT_EQ(2,    vector_of_1st_row.size());
    EXPECT_EQ(15,   vector_of_1st_row.at(0));
    EXPECT_EQ(-100, vector_of_1st_row.at(1));
    EXPECT_EQ(2,    vector_of_2nd_row.size());
    EXPECT_EQ(1,    vector_of_2nd_row.at(0));
    EXPECT_EQ(123,  vector_of_2nd_row.at(1));
}

TEST(MatrixMultiplicateWithAnotherMatrix, Matrices2x2)
{
    Matrix<int> matrix1(2, 2);
    matrix1.setElement(1, 0, 0);
    matrix1.setElement(2, 0, 1);
    matrix1.setElement(3, 1, 0);
    matrix1.setElement(4, 1, 1);
    Matrix<int> matrix2(2, 2);
    matrix2.setElement(5, 0, 0);
    matrix2.setElement(6, 0, 1);
    matrix2.setElement(7, 1, 0);
    matrix2.setElement(8, 1, 1);
    Matrix<int> result = matrix1 * matrix2;

    EXPECT_EQ(2, matrix1.getRowsNumber());
    EXPECT_EQ(2, matrix1.getColumnsNumber());
    EXPECT_EQ(1, matrix1.getElement(0, 0));
    EXPECT_EQ(2, matrix1.getElement(0, 1));
    EXPECT_EQ(3, matrix1.getElement(1, 0));
    EXPECT_EQ(4, matrix1.getElement(1, 1));

    EXPECT_EQ(2, matrix2.getRowsNumber());
    EXPECT_EQ(2, matrix2.getColumnsNumber());
    EXPECT_EQ(5, matrix2.getElement(0, 0));
    EXPECT_EQ(6, matrix2.getElement(0, 1));
    EXPECT_EQ(7, matrix2.getElement(1, 0));
    EXPECT_EQ(8, matrix2.getElement(1, 1));

    EXPECT_EQ(2, result.getRowsNumber());
    EXPECT_EQ(2, result.getColumnsNumber());
    EXPECT_EQ(19, result.getElement(0, 0));
    EXPECT_EQ(22, result.getElement(0, 1));
    EXPECT_EQ(43, result.getElement(1, 0));
    EXPECT_EQ(50, result.getElement(1, 1));
}

TEST(MatrixMultiplicateWithVector, Matrix2x2AndVectorWith2Elements)
{
    Matrix<int> matrix(2, 2);
    matrix.setElement(1, 0, 0);
    matrix.setElement(2, 0, 1);
    matrix.setElement(3, 1, 0);
    matrix.setElement(4, 1, 1);
    std::vector<int> vector;
    vector.push_back(5);
    vector.push_back(6);
    Matrix<int> result = matrix * Matrix<int>(vector);

    EXPECT_EQ(2, matrix.getRowsNumber());
    EXPECT_EQ(2, matrix.getColumnsNumber());
    EXPECT_EQ(1, matrix.getElement(0, 0));
    EXPECT_EQ(2, matrix.getElement(0, 1));
    EXPECT_EQ(3, matrix.getElement(1, 0));
    EXPECT_EQ(4, matrix.getElement(1, 1));

    EXPECT_EQ(2, vector.size());
    EXPECT_EQ(5, vector.at(0));
    EXPECT_EQ(6, vector.at(1));

    EXPECT_EQ(2, result.getRowsNumber());
    EXPECT_EQ(1, result.getColumnsNumber());
    EXPECT_EQ(17, result.getElement(0, 0));
    EXPECT_EQ(39, result.getElement(1, 0));
}

TEST(MatrixAddWithAnotherMatrix, Matrices2x2)
{
    Matrix<int> matrix1(2, 2);
    matrix1.setElement(1, 0, 0);
    matrix1.setElement(2, 0, 1);
    matrix1.setElement(3, 1, 0);
    matrix1.setElement(4, 1, 1);
    
    Matrix<int> matrix2(2, 2);
    matrix2.setElement(5, 0, 0);
    matrix2.setElement(6, 0, 1);
    matrix2.setElement(7, 1, 0);
    matrix2.setElement(8, 1, 1);

    Matrix<int> result = matrix1 + matrix2;
    
    EXPECT_EQ(2,  result.getRowsNumber());
    EXPECT_EQ(2,  result.getColumnsNumber());
    EXPECT_EQ(6,  result.getElement(0, 0));
    EXPECT_EQ(8,  result.getElement(0, 1));
    EXPECT_EQ(10, result.getElement(1, 0));
    EXPECT_EQ(12, result.getElement(1, 1));
}

TEST(MatrixAddWithAnotherMatrix, MatricesWithDifferentSizes)
{
    Matrix<int> matrix1(2, 1, 0);
    Matrix<int> matrix2(2, 2, 1);

    Matrix<int> result = matrix1 + matrix2;
    EXPECT_EQ(0, result.getRowsNumber());
    EXPECT_EQ(0, result.getColumnsNumber());
}

TEST(MatrixIsEmpty, AllCases)
{
    Matrix<int> matrix1;
    Matrix<int> matrix2(1,  1);
    Matrix<int> matrix3(0,  0);
    Matrix<int> matrix4(3,  0);
    Matrix<int> matrix5(0,  2);
    Matrix<int> matrix6(5,  7);
    Matrix<int> matrix7(15, 12);
    EXPECT_TRUE (matrix1.isEmpty());
    EXPECT_FALSE(matrix2.isEmpty());
    EXPECT_TRUE (matrix3.isEmpty());
    EXPECT_TRUE (matrix4.isEmpty());
    EXPECT_TRUE (matrix5.isEmpty());
    EXPECT_FALSE(matrix6.isEmpty());
    EXPECT_FALSE(matrix7.isEmpty());
}

TEST(MatrixIsNull, AllCases)
{
    Matrix<int> matrix1;
    Matrix<int> matrix2(1,  1);
    Matrix<int> matrix3(0,  0);
    Matrix<int> matrix4(3,  0);
    Matrix<int> matrix5(0,  2);
    Matrix<int> matrix6(5,  7);
    Matrix<int> matrix7(15, 12);
    EXPECT_TRUE (matrix1.isNull());
    EXPECT_FALSE(matrix2.isNull());
    EXPECT_TRUE (matrix3.isNull());
    EXPECT_FALSE(matrix4.isNull());
    EXPECT_FALSE(matrix5.isNull());
    EXPECT_FALSE(matrix6.isNull());
    EXPECT_FALSE(matrix7.isNull());
}

TEST(MatrixIsZero, NullMatrix)
{
    Matrix<int> matrix;
    EXPECT_FALSE(matrix.isZeroMatrix());
}

TEST(MatrixIsZero, EmptyMatrix)
{
    Matrix<int> matrix1(3, 0);
    EXPECT_FALSE(matrix1.isZeroMatrix());
    Matrix<int> matrix2(0, 5);
    EXPECT_FALSE(matrix2.isZeroMatrix());
}

TEST(MatrixIsZero, ZeroMatrix)
{
    Matrix<int> matrix1(1, 1);
    Matrix<double> matrix2(2, 2);
    EXPECT_TRUE(matrix1.isZeroMatrix());
    EXPECT_TRUE(matrix2.isZeroMatrix());
}

TEST(MatrixIsZero, NonZeroMatrix)
{
    Matrix<int> matrix1(1, 1);
    matrix1.setElement(5, 0, 0);
    Matrix<double> matrix2(2, 2);
    matrix2.setElement(1.234567, 1, 1);
    Matrix<int> matrix3(5, 10);
    matrix3.setElement(5, 4, 5);
    matrix3.setElement(-10, 2, 7);
    matrix3.setElement(150, 0, 2);
    Matrix<int> matrix4(12, 7);
    matrix4.setElement(-701, 10, 5);
    matrix4.setElement(1233, 2, 5);
    matrix4.setElement(45, 11, 6);
    EXPECT_FALSE(matrix1.isZeroMatrix());
    EXPECT_FALSE(matrix2.isZeroMatrix());
    EXPECT_FALSE(matrix3.isZeroMatrix());
    EXPECT_FALSE(matrix4.isZeroMatrix());
}

TEST(MatrixUnaryOperatorMinus, SimpleNegateOfNonZeroMatrix2x2)
{
    Matrix<int> test_matrix(2, 2);
    test_matrix.setElement( 15,  0, 0);
    test_matrix.setElement(-16,  1, 0);
    test_matrix.setElement( 17,  0, 1);
    test_matrix.setElement(-115, 1, 1);
    
    Matrix<int> negate_test_matrix = -test_matrix;
    EXPECT_EQ( 15,  test_matrix.getElement(0, 0));
    EXPECT_EQ(-16,  test_matrix.getElement(1, 0));
    EXPECT_EQ( 17,  test_matrix.getElement(0, 1));
    EXPECT_EQ(-115, test_matrix.getElement(1, 1));
    EXPECT_EQ(2,    test_matrix.getRowsNumber());
    EXPECT_EQ(2,    test_matrix.getColumnsNumber());
    

    EXPECT_EQ(-15,  negate_test_matrix.getElement(0, 0));
    EXPECT_EQ( 16,  negate_test_matrix.getElement(1, 0));
    EXPECT_EQ(-17,  negate_test_matrix.getElement(0, 1));
    EXPECT_EQ( 115, negate_test_matrix.getElement(1, 1));
    EXPECT_EQ(2,    negate_test_matrix.getRowsNumber());
    EXPECT_EQ(2,    negate_test_matrix.getColumnsNumber());
}

TEST(MatrixUnaryOperatorMinus, NullMatrix)
{
    Matrix<double> null_matrix;
    Matrix<double> negate_of_null_matrix = -null_matrix;
    EXPECT_TRUE(null_matrix.isNull());
    EXPECT_TRUE(negate_of_null_matrix.isNull());
}

TEST(MatrixUnaryOperatorMinus, ZeroMatrixAllCases)
{
    Matrix<int> matrix_with_zero_rows(0, 5);
    Matrix<int> matrix_with_zero_columns(7, 0);
    Matrix<int> negate_of_matrix_with_zero_rows = -matrix_with_zero_rows;
    Matrix<int> negate_of_matrix_with_zero_columns = -matrix_with_zero_columns;
    EXPECT_EQ(0, matrix_with_zero_rows.getRowsNumber());
    EXPECT_EQ(5, matrix_with_zero_rows.getColumnsNumber());
    EXPECT_EQ(7, matrix_with_zero_columns.getRowsNumber());
    EXPECT_EQ(0, matrix_with_zero_columns.getColumnsNumber());
    EXPECT_EQ(matrix_with_zero_rows.getRowsNumber(), 
              negate_of_matrix_with_zero_rows.getRowsNumber());
    EXPECT_EQ(matrix_with_zero_rows.getColumnsNumber(), 
              negate_of_matrix_with_zero_rows.getColumnsNumber());
    EXPECT_EQ(matrix_with_zero_columns.getRowsNumber(), 
              negate_of_matrix_with_zero_columns.getRowsNumber());
    EXPECT_EQ(matrix_with_zero_columns.getColumnsNumber(), 
              negate_of_matrix_with_zero_columns.getColumnsNumber());
}
