#include <gtest/gtest.h>
#include "../sources/Matrix.h"
#include "sources/exceptions/ColumnIndexOutOfRange.h"
#include "sources/exceptions/MatricesCantBeMultiplied.h"
#include "sources/exceptions/RangeError.h"
#include "sources/exceptions/RowIndexOutOfRange.h"
#include <vector>
#include <string>

TEST(MatrixConstructor, DefaultConstructor)
{
    Matrix<int> matrix;
    EXPECT_EQ(0, matrix.elements_.size());
}

TEST(MatrixConstructor, DefaultMatrix1x1)
{
    Matrix<int> matrix(1, 1);
    EXPECT_EQ(1, matrix.elements_.size());
    EXPECT_EQ(1, matrix.elements_.at(0).size());
    EXPECT_EQ(0, matrix.elements_.at(0).at(0));
}

TEST(MatrixConstructor, DefaultMatrix2x2)
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

TEST(MatrixSetRowsNumber, set3RowsForNewMatrix)
{
    Matrix<int> matrix;
    matrix.setRowsNumber(3);
    EXPECT_EQ(3, matrix.elements_.size());
    EXPECT_EQ(0, matrix.elements_.at(0).size());
    EXPECT_EQ(0, matrix.elements_.at(1).size());
    EXPECT_EQ(0, matrix.elements_.at(2).size());
}

TEST(MatrixIsElementIndexInRange, TestCase)
{
    Matrix<int> matrix(2, 3);
    EXPECT_TRUE(matrix.isElementIndexInRange(0, 0));
    EXPECT_TRUE(matrix.isElementIndexInRange(1, 2));
    EXPECT_FALSE(matrix.isElementIndexInRange(-1, -2));
    EXPECT_FALSE(matrix.isElementIndexInRange(2, 3));
    EXPECT_FALSE(matrix.isElementIndexInRange(3, 2));
    EXPECT_FALSE(matrix.isElementIndexInRange(1, 5));
}

TEST(MatrixSetElement, SomeRandomElementsInMatrix3x4)
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
    using namespace MatrixExceptions;
    EXPECT_THROW(matrix.setElement(2, 2, 2), RowIndexOutOfRange);
    EXPECT_THROW(matrix.setElement(112, 1, 5), ColumnIndexOutOfRange);
    EXPECT_THROW(matrix.setElement(1234, 15, 10), RowIndexOutOfRange);
    
}

TEST(MatrixGetElement, SomeRandomElementsInMatrix3x4)
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
    EXPECT_THROW(matrix.getElement(1, 5), ColumnIndexOutOfRange);
    EXPECT_THROW(matrix.getElement(5, 2), RowIndexOutOfRange);
    EXPECT_THROW(matrix.getElement(5, 5), RowIndexOutOfRange);
}

TEST(MatrixSetColumnsNumber, set3ColumnsForMatrix2x2)
{
    Matrix<int> matrix(2, 2);
    matrix.setColumnsNumber(3);
    EXPECT_EQ(3, matrix.elements_.at(0).size());
    EXPECT_EQ(3, matrix.elements_.at(1).size());
    EXPECT_EQ(2, matrix.elements_.size());
}

TEST(MatrixSetColumnsNumber, set3ColumnsForMatrix2x2WithNotZeroElements)
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

TEST(MatrixGetElementsToCopyFromVector, AllCases)
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

TEST(MatrixSetElementsFromVector, VectorWith5Elements)
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

TEST(MatrixSetElementsFromVector, VectorWithMoreElementsThanInMatrix)
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

TEST(MatrixPutToStreamOperator, MatrixWithFiveSevens)
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

TEST(MatrixPutToStreamOperator, Matrix0x0)
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
    vector<int> vector_of_1st_row = getRowVector(matrix, 0);
    vector<int> vector_of_2nd_row = getRowVector(matrix, 1);
    EXPECT_EQ(0, vector_of_1st_row.size());
    EXPECT_EQ(0, vector_of_2nd_row.size());
}

TEST(MatrixGetRowVector, Matrix1x1)
{
    Matrix<int> matrix(1, 1);
    matrix.setElement(15, 0, 0);
    vector<int> vector_of_1st_row = getRowVector(matrix, 0);
    vector<int> vector_of_2nd_row = getRowVector(matrix, 1);
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
    vector<int> vector_of_1st_row = getRowVector(matrix, 0);
    vector<int> vector_of_2nd_row = getRowVector(matrix, 1);
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

TEST(MatrixMultiplicateWithAnotherMatrix, CantBeMultiplied)
{
    Matrix<int> matrix1(1, 2);
    Matrix<int> matrix2(3, 3);
    EXPECT_THROW(matrix1 * matrix2, MatricesCantBeMultiplied);
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

TEST(MatrixIsEmpty, AllCases)
{
    Matrix<int> matrix1;
    Matrix<int> matrix2(1,  1);
    Matrix<int> matrix3(0,  0);
    Matrix<int> matrix4(3,  0);
    Matrix<int> matrix5(0,  2);
    Matrix<int> matrix6(5,  7);
    Matrix<int> matrix7(15, 12);
    EXPECT_TRUE (isEmpty(matrix1));
    EXPECT_FALSE(isEmpty(matrix2));
    EXPECT_TRUE (isEmpty(matrix3));
    EXPECT_TRUE (isEmpty(matrix4));
    EXPECT_TRUE (isEmpty(matrix5));
    EXPECT_FALSE(isEmpty(matrix6));
    EXPECT_FALSE(isEmpty(matrix7));
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
    EXPECT_TRUE (isNull(matrix1));
    EXPECT_FALSE(isNull(matrix2));
    EXPECT_TRUE (isNull(matrix3));
    EXPECT_FALSE(isNull(matrix4));
    EXPECT_FALSE(isNull(matrix5));
    EXPECT_FALSE(isNull(matrix6));
    EXPECT_FALSE(isNull(matrix7));
}

TEST(MatrixIsZero, NullMatrix)
{
    Matrix<int> matrix;
    EXPECT_FALSE(isZeroMatrix(matrix));
}

TEST(MatrixIsZero, EmptyMatrix)
{
    Matrix<int> matrix1(3, 0);
    EXPECT_FALSE(isZeroMatrix(matrix1));
    Matrix<int> matrix2(0, 5);
    EXPECT_FALSE(isZeroMatrix(matrix2));
}

TEST(MatrixIsZero, ZeroMatrix)
{
    Matrix<int> matrix1(1, 1);
    Matrix<double> matrix2(2, 2);
    EXPECT_TRUE(isZeroMatrix(matrix1));
    EXPECT_TRUE(isZeroMatrix(matrix2));
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
    EXPECT_FALSE(isZeroMatrix(matrix1));
    EXPECT_FALSE(isZeroMatrix(matrix2));
    EXPECT_FALSE(isZeroMatrix(matrix3));
    EXPECT_FALSE(isZeroMatrix(matrix4));
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
    EXPECT_TRUE(isNull(null_matrix));
    EXPECT_TRUE(isNull(negate_of_null_matrix));
}

TEST(MatrixUnaryOperatorMinus, EmptyMatrixAllCases)
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

TEST(MatrixHaveSameSize, AllCases)
{
    Matrix<int> null_matrix;
    Matrix<int> zero_matrix_5x4(5, 4);
    Matrix<int> non_zero_matrix_5x4(5, 4);
    non_zero_matrix_5x4.setElement(123, 1, 2);
    non_zero_matrix_5x4.setElement(-123, 0, 2);
    non_zero_matrix_5x4.setElement(1, 1, 3);
    non_zero_matrix_5x4.setElement(2, 2, 3);
    non_zero_matrix_5x4.setElement(3, 3, 3);
    non_zero_matrix_5x4.setElement(4, 4, 3);
    EXPECT_FALSE(   haveSameSize(null_matrix,           zero_matrix_5x4)    );
    EXPECT_FALSE(   haveSameSize(null_matrix,           non_zero_matrix_5x4));
    EXPECT_TRUE(    haveSameSize(zero_matrix_5x4,       non_zero_matrix_5x4));
    EXPECT_TRUE(    haveSameSize(non_zero_matrix_5x4,   zero_matrix_5x4)    );
}

TEST(MatrixOperatorPlus, Matrix3x3PlusMatrix3x3)
{
    Matrix<int> first_matrix3x3(3, 3, 2);
    first_matrix3x3.setElement(5, 0, 0);
    first_matrix3x3.setElement(-5, 1, 0);
    first_matrix3x3.setElement(10, 2, 2);
    Matrix<int> second_matrix3x3(3, 3, 1);
    second_matrix3x3.setElement(-17, 2, 1);
    second_matrix3x3.setElement(-5, 0, 0);
    second_matrix3x3.setElement(123, 1, 1);
    Matrix<int> result = first_matrix3x3 + second_matrix3x3;
    EXPECT_EQ( 3,   result.getRowsNumber());
    EXPECT_EQ( 3,   result.getColumnsNumber());
    EXPECT_EQ( 0,   result.getElement(0, 0));
    EXPECT_EQ( 3,   result.getElement(0, 1));
    EXPECT_EQ( 3,   result.getElement(0, 2));
    EXPECT_EQ(-4,   result.getElement(1, 0));
    EXPECT_EQ( 125, result.getElement(1, 1));
    EXPECT_EQ( 3,   result.getElement(1, 2));
    EXPECT_EQ( 3,   result.getElement(2, 0));
    EXPECT_EQ(-15,  result.getElement(2, 1));
    EXPECT_EQ( 11,  result.getElement(2, 2));
}

TEST(MatrixOperatorPlus, NullAndEmptyMatrices)
{
    Matrix<int> null_matrix;
    Matrix<int> result_after_plus_of_null_matrixes = null_matrix + null_matrix;
    EXPECT_TRUE(isNull(result_after_plus_of_null_matrixes));
    
    Matrix<int> empty_matrix3x0(3, 0);
    Matrix<int> empty_matrix0x3(0, 3);
    Matrix<int> result_after_plus_of_matrix_3x0 = 
        empty_matrix3x0 + empty_matrix3x0;
    Matrix<int> result_after_plus_of_matrix_0x3 = 
        empty_matrix0x3 + empty_matrix0x3;
    EXPECT_EQ(3, result_after_plus_of_matrix_3x0.getRowsNumber());
    EXPECT_EQ(0, result_after_plus_of_matrix_3x0.getColumnsNumber());
    EXPECT_EQ(0, result_after_plus_of_matrix_0x3.getRowsNumber());
    EXPECT_EQ(3, result_after_plus_of_matrix_0x3.getColumnsNumber());
}

TEST(MatrixOperatorPlus, SizesAreNotEqual)
{
    Matrix<int> matrix2x3(2, 3);
    Matrix<int> matrix3x3(3, 3);
    EXPECT_THROW(matrix2x3 + matrix3x3, MatricesCantBeAddedOrSubstracted);
}

TEST(MatrixOperatorMinus, Matrix3x3MinusMatrix3x3)
{
    Matrix<int> first_matrix3x3(3, 3, 2);
    first_matrix3x3.setElement(5, 0, 0);
    first_matrix3x3.setElement(-5, 1, 0);
    first_matrix3x3.setElement(10, 2, 2);
    Matrix<int> second_matrix3x3(3, 3, 1);
    second_matrix3x3.setElement(-17, 2, 1);
    second_matrix3x3.setElement(-5, 0, 0);
    second_matrix3x3.setElement(123, 1, 1);
    Matrix<int> result = first_matrix3x3 - second_matrix3x3;
    EXPECT_EQ( 3,   result.getRowsNumber());
    EXPECT_EQ( 3,   result.getColumnsNumber());
    EXPECT_EQ( 10,  result.getElement(0, 0));
    EXPECT_EQ( 1,   result.getElement(0, 1));
    EXPECT_EQ( 1,   result.getElement(0, 2));
    EXPECT_EQ(-6,   result.getElement(1, 0));
    EXPECT_EQ(-121, result.getElement(1, 1));
    EXPECT_EQ( 1,   result.getElement(1, 2));
    EXPECT_EQ( 1,   result.getElement(2, 0));
    EXPECT_EQ( 19,  result.getElement(2, 1));
    EXPECT_EQ( 9,   result.getElement(2, 2));
}

TEST(MatrixOperatorMinus, NullAndEmptyMatrices)
{
    Matrix<int> null_matrix;
    Matrix<int> result_after_plus_of_null_matrixes = null_matrix - null_matrix;
    EXPECT_TRUE(isNull(result_after_plus_of_null_matrixes));
    
    Matrix<int> empty_matrix3x0(3, 0);
    Matrix<int> empty_matrix0x3(0, 3);
    Matrix<int> result_after_plus_of_matrix_3x0 = 
        empty_matrix3x0 - empty_matrix3x0;
    Matrix<int> result_after_plus_of_matrix_0x3 = 
        empty_matrix0x3 - empty_matrix0x3;
    EXPECT_EQ(3, result_after_plus_of_matrix_3x0.getRowsNumber());
    EXPECT_EQ(0, result_after_plus_of_matrix_3x0.getColumnsNumber());
    EXPECT_EQ(0, result_after_plus_of_matrix_0x3.getRowsNumber());
    EXPECT_EQ(3, result_after_plus_of_matrix_0x3.getColumnsNumber());
}

TEST(MatrixOperatorMinus, SizesAreNotEqual)
{
    Matrix<int> matrix2x3(2, 3);
    Matrix<int> matrix3x3(3, 3);
    EXPECT_THROW(matrix2x3 + matrix3x3, MatricesCantBeAddedOrSubstracted);
}

TEST(MatrixOperatorIsEqual, AllCases)
{
    Matrix<int> matrix3x3_with_10s(3, 3, 10);
    Matrix<int> matrix3x3_with_11s(3, 3, 11);
    Matrix<int> matrix2x3_with_10s(2, 3, 10);
    Matrix<int> another_matrix3x3_with_10s(3, 3, 10);
    EXPECT_FALSE(matrix3x3_with_10s == matrix3x3_with_11s);
    EXPECT_FALSE(matrix3x3_with_10s == matrix2x3_with_10s);
    EXPECT_TRUE(matrix3x3_with_10s == matrix3x3_with_10s);
    EXPECT_TRUE(matrix3x3_with_10s == another_matrix3x3_with_10s);
    EXPECT_TRUE(another_matrix3x3_with_10s == matrix3x3_with_10s);
}

TEST(MatrixConstructor, FromMatrixOfDifferentType)
{
    Matrix<double> double_matrix(3, 3);
    double_matrix.setElement(7.5,       0, 0);
    double_matrix.setElement(9.7,       0, 1);
    double_matrix.setElement(1.0,       0, 2);
    double_matrix.setElement(6.12,      1, 0);
    double_matrix.setElement(5.87,      1, 1);
    double_matrix.setElement(2.6457,    1, 2);
    double_matrix.setElement(4.102,     2, 0);
    double_matrix.setElement(8.77,      2, 1);
    double_matrix.setElement(3.123,     2, 2);
    
    Matrix<int> int_matrix = double_matrix;
    
    EXPECT_TRUE(haveSameSize(double_matrix, int_matrix));
    EXPECT_EQ(int_matrix.getElement(0, 0), 7);
    EXPECT_EQ(int_matrix.getElement(0, 1), 9);
    EXPECT_EQ(int_matrix.getElement(0, 2), 1);
    EXPECT_EQ(int_matrix.getElement(1, 0), 6);
    EXPECT_EQ(int_matrix.getElement(1, 1), 5);
    EXPECT_EQ(int_matrix.getElement(1, 2), 2);
    EXPECT_EQ(int_matrix.getElement(2, 0), 4);
    EXPECT_EQ(int_matrix.getElement(2, 1), 8);
    EXPECT_EQ(int_matrix.getElement(2, 2), 3);
}

TEST(MatrixIsSquare, AllCases)
{
    Matrix<int> square_matrix_2x2(2, 2);
    Matrix<int> square_matrix_0x0(2, 2);
    Matrix<int> not_square_matrix_1x0(1, 0);
    Matrix<int> not_square_matrix_1x3(1, 3);
    EXPECT_TRUE(isSquare(square_matrix_2x2));
    EXPECT_TRUE(isSquare(square_matrix_0x0));
    EXPECT_FALSE(isSquare(not_square_matrix_1x0));
    EXPECT_FALSE(isSquare(not_square_matrix_1x3));
}

TEST(MatrixGetColumnVector, Matrix3x3)
{
    Matrix<int> matrix3x3(3, 3);
    matrix3x3.setElement(7, 0, 0);
    matrix3x3.setElement(9, 0, 1);
    matrix3x3.setElement(1, 0, 2);
    matrix3x3.setElement(6, 1, 0);
    matrix3x3.setElement(5, 1, 1);
    matrix3x3.setElement(2, 1, 2);
    matrix3x3.setElement(4, 2, 0);
    matrix3x3.setElement(8, 2, 1);
    matrix3x3.setElement(3, 2, 2);
    
    vector<int> first_column = getColumnVector(matrix3x3, 0);
    vector<int> second_column = getColumnVector(matrix3x3, 1);
    
    EXPECT_EQ(3, first_column.size());
    EXPECT_EQ(7, first_column.at(0));
    EXPECT_EQ(6, first_column.at(1));
    EXPECT_EQ(4, first_column.at(2));

    EXPECT_EQ(3, second_column.size());
    EXPECT_EQ(9, second_column.at(0));
    EXPECT_EQ(5, second_column.at(1));
    EXPECT_EQ(8, second_column.at(2));
}

TEST(MatrixGetColumnVector, EmptyColumnCases)
{
    Matrix<int> matrix2x0 (2, 0, 1);
    Matrix<int> matrix0x0 (0, 0);
    
    EXPECT_EQ(0, getColumnVector(matrix2x0, 0).size());
    EXPECT_EQ(0, getColumnVector(matrix0x0, 0).size());
}

TEST(MatrixGetElementReference, SeveralCases)
{
    Matrix<int> matrix3x3(3, 3);
    matrix3x3.setElement(7, 0, 0);
    matrix3x3.setElement(9, 0, 1);
    matrix3x3.setElement(1, 0, 2);
    matrix3x3.setElement(6, 1, 0);
    matrix3x3.setElement(5, 1, 1);
    matrix3x3.setElement(2, 1, 2);
    matrix3x3.setElement(4, 2, 0);
    matrix3x3.setElement(8, 2, 1);
    matrix3x3.setElement(3, 2, 2);
    
    matrix3x3.getElementReference(1, 0) = 5;
    EXPECT_EQ(5, matrix3x3.getElement(1, 0));
}
