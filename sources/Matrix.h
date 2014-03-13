#ifndef MATRIX_H
#define	MATRIX_H
#include <vector>
#include <gtest/gtest_prod.h>
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
using std::vector;

typedef std::size_t natural;

template<typename CUSTOM_TYPE>
class Matrix {
    FRIEND_TEST(TestMatrixConstructor, DefaultConstructor);
    FRIEND_TEST(TestMatrixConstructor, DefaultMatrix1x1);
    FRIEND_TEST(TestMatrixConstructor, DefaultMatrix2x2);
    FRIEND_TEST(TestMatrixSetRowsNumber, set3RowsForNewMatrix);
    FRIEND_TEST(TestMatrixIsElementIndexInRange, TestCase);
    FRIEND_TEST(TestMatrixSetElement, SomeRandomElementsInMatrix3x4);
    FRIEND_TEST(TestMatrixSetColumnsNumber, set3ColumnsForMatrix2x2);
    FRIEND_TEST(TestMatrixSetColumnsNumber, 
                set3ColumnsForMatrix2x2WithNotZeroElements);
    FRIEND_TEST(TestMatrixGetElementsToCopyFromVector, AllCases);
    FRIEND_TEST(MatrixIsMultiplyPossible, AllCasesWithVector);
public:
    typedef typename vector<vector<CUSTOM_TYPE> >::iterator RowsIterator;
    typedef typename vector<CUSTOM_TYPE>::const_iterator VectorConstIterator;
    
    
    Matrix(const natural rows_number          = 0, 
           const natural columns_number       = 0, 
           const CUSTOM_TYPE initialize_value = 0)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber       (rows_number,       initialize_value);
        setColumnsNumber    (columns_number,    initialize_value);
    }
    
    Matrix(const natural rows_number, 
           const natural columns_number, 
           const vector<CUSTOM_TYPE>& elements,
           const CUSTOM_TYPE initialize_value = 0)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber       (rows_number,       initialize_value);
        setColumnsNumber    (columns_number,    initialize_value);
        setElementsFromVector(elements);
    }
    
    Matrix(const vector<CUSTOM_TYPE> &vector_to_convert)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber(vector_to_convert.size());
        setColumnsNumber(1);
        setElementsFromVector(vector_to_convert);
    }
    
    void setColumnsNumber(const natural columns_number,
                          const CUSTOM_TYPE initialize_value = 0)
    {
        RowsIterator rows_iterator;
        for(rows_iterator = elements_.begin(); 
            rows_iterator != elements_.end(); 
            ++rows_iterator)
        {
            rows_iterator->resize(columns_number, initialize_value);
        }
        columns_number_ = columns_number;
    }
    
    natural getColumnsNumber() const
    {   
        return columns_number_;
    }
    
    void setRowsNumber(const natural rows_number,
                       const CUSTOM_TYPE initialize_value = 0)
    {
        elements_.resize(rows_number, 
                         vector<CUSTOM_TYPE>(getColumnsNumber(), 
                                                  initialize_value));
        rows_number_ = rows_number;
    }
    
    natural getRowsNumber() const
    {
        return rows_number_;
    }
    
    void setElement(const CUSTOM_TYPE value, 
                    const natural row_number, 
                    const natural column_number)
    {
        if(isElementIndexInRange(row_number, column_number))
        {
            elements_.at(row_number).at(column_number) = value;
        }
    }
    
    CUSTOM_TYPE getElement(const natural row_number, 
                           const natural column_number) const
    {
        if(isElementIndexInRange(row_number, column_number))
        {
            return elements_.at(row_number).at(column_number);
        }
    }
    
    void setElementsFromVector(const vector<CUSTOM_TYPE> &elements)
    {
        VectorConstIterator elements_iterator = 
            elements.begin();
        RowsIterator rows_iterator;
        for(rows_iterator = elements_.begin(); 
            rows_iterator != elements_.end();
            rows_iterator++)
        {
            natural elements_to_copy = 
                getNumberOfElementsToCopyFromVector(elements_iterator,
                                                    elements.end());
            std::copy(elements_iterator, 
                      elements_iterator + elements_to_copy, 
                      rows_iterator->begin());
            elements_iterator += elements_to_copy;
        }
    }
    
    void getElementsToVector(vector<CUSTOM_TYPE> &elements_vector) const;
private:
    natural rows_number_;
    natural columns_number_;
    vector<vector<CUSTOM_TYPE> > elements_;
    
    bool isMultiplyPossibleWith(const Matrix<CUSTOM_TYPE>& matrix_operand) const
    {
        return getColumnsNumber() == matrix_operand.getRowsNumber();
    }
    
    bool isElementIndexInRange(const natural row_number, 
                               const natural column_number) const
    {
        return row_number       < getRowsNumber() &&
               row_number       >= 0 &&
               column_number    < getColumnsNumber() &&
               column_number    >= 0;
    }
    
    natural getNumberOfElementsToCopyFromVector(
              VectorConstIterator current_element_iterator,
              VectorConstIterator vector_end_iterator)
    {
        natural elements_last = 
            vector_end_iterator - current_element_iterator;
        natural elements_to_copy = 0;
        if(elements_last < getColumnsNumber())
        {
            elements_to_copy = elements_last;
        }
        else
        {
            elements_to_copy = getColumnsNumber();
        }
    }
};

template <typename MATRIX_VALUE_TYPE>
Matrix<MATRIX_VALUE_TYPE> operator*(const Matrix<MATRIX_VALUE_TYPE>& matrix, 
                                    const MATRIX_VALUE_TYPE value)
{   
    Matrix<MATRIX_VALUE_TYPE> result(matrix.getRowsNumber(), 
                                     matrix.getColumnsNumber());
    for(natural row_index = 0; row_index < matrix.getRowsNumber(); ++row_index)
    {
        for(natural column_index = 0; 
            column_index < matrix.getColumnsNumber(); 
            ++column_index)
        {
            MATRIX_VALUE_TYPE current_element = 
                matrix.getElement(row_index, column_index);
            result.setElement(current_element * value, row_index, column_index);
        }
    }

    return result;
}

template <typename MATRIX_VALUE_TYPE>
std::ostream& operator<<(std::ostream &result, 
                         Matrix<MATRIX_VALUE_TYPE> matrix)
{
    for(natural row_index = 0; row_index < matrix.getRowsNumber(); ++row_index)
    {
        for(natural column_index = 0; 
            column_index < matrix.getColumnsNumber(); 
            ++column_index)
        {
            result << matrix.getElement(row_index, column_index) << "\t";
        }
        result << std::endl;
    }
    return result;
}

template <typename MATRIX_VALUE_TYPE>
Matrix<MATRIX_VALUE_TYPE> operator*(const Matrix<MATRIX_VALUE_TYPE> &left, 
                                     const Matrix<MATRIX_VALUE_TYPE> &right);

template <typename MATRIX_VALUE_TYPE>
Matrix<MATRIX_VALUE_TYPE> operator+(const Matrix<MATRIX_VALUE_TYPE> &left, 
                                     const Matrix<MATRIX_VALUE_TYPE> &right);

template <typename MATRIX_VALUE_TYPE>
Matrix<MATRIX_VALUE_TYPE> operator-(const Matrix<MATRIX_VALUE_TYPE> &left, 
                                     const Matrix<MATRIX_VALUE_TYPE> &right);

template <typename MATRIX_VALUE_TYPE>
bool operator==(const Matrix<MATRIX_VALUE_TYPE> &left, 
                const Matrix<MATRIX_VALUE_TYPE> &right);

#endif	/* MATRIX_H */

