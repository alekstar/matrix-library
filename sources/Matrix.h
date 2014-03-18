#ifndef MATRIX_H
#define	MATRIX_H
#include <vector>
using std::vector;
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>

#include <gtest/gtest_prod.h>

#include "natural_type.h"
#include "VectorMathAlgorithms.h"
#include "MatrixRowIndexOutOfRange.h"
#include "MatrixColumnIndexOutOfRange.h"

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
    FRIEND_TEST(MatrixGetRowVector, Matrix0x0);
    FRIEND_TEST(MatrixGetRowVector, Matrix1x1);
    FRIEND_TEST(MatrixGetRowVector, Matrix2x2);
    FRIEND_TEST(MatrixHaveSameSize, AllCases);
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
            throw(MatrixRowIndexOutOfRange, MatrixColumnIndexOutOfRange)
    {
        if(isElementIndexInRange(row_number, column_number))
        {
            elements_.at(row_number).at(column_number) = value;
        }
        if(!isRowIndexInRange(row_number))
        {
            throw MatrixRowIndexOutOfRange();
        }
        if(!isColumnIndexInRange(column_number))
        {
            throw MatrixColumnIndexOutOfRange();
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
        
    Matrix<CUSTOM_TYPE> operator*(const CUSTOM_TYPE value) {
        Matrix<CUSTOM_TYPE> result(getRowsNumber(),
                                         getColumnsNumber());
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index) {
            for(natural column_index = 0;
                column_index < getColumnsNumber();
                ++column_index) {
                CUSTOM_TYPE current_element =
                    getElement(row_index, column_index);
                result.setElement(current_element * value, 
                                  row_index, 
                                  column_index);
            }
        }

        return result;
    }
    
    Matrix<CUSTOM_TYPE> operator*(const Matrix<CUSTOM_TYPE> &operand) const
    {
        using vectorMathAlogirthms::makeScalarMultiplication;
        if(getColumnsNumber() != operand.getRowsNumber())
        {
            return getNullMatrix();
        }
        Matrix<CUSTOM_TYPE> result(getRowsNumber(), operand.getColumnsNumber());
        for(natural row_index = 0; 
            row_index < result.getRowsNumber(); 
            ++row_index)
        {
            for(natural column_index = 0;
                column_index < result.getColumnsNumber();
                ++column_index)
            {
                result.setElement(
                    makeScalarMultiplication(
                        getRowVector(row_index), 
                        operand.getColumnVector(column_index)), 
                    row_index, 
                    column_index);
            }
        }
        return result;
    }
    
    Matrix<CUSTOM_TYPE> operator+(const Matrix<CUSTOM_TYPE> &operand) const
    {
        if(!haveSameSize(operand))
        {
            return getNullMatrix();
        }
        Matrix<CUSTOM_TYPE> result(getRowsNumber(), getColumnsNumber());
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index)
        {
            for(natural column_index = 0; 
                column_index < getColumnsNumber(); 
                ++column_index)
            {
                result.setElement(getElement(row_index, column_index) + 
                                  operand.getElement(row_index, column_index),
                                  row_index,
                                  column_index);
            }
        }
        return result;
    }
    
    Matrix<CUSTOM_TYPE> operator-() const
    {
        Matrix<CUSTOM_TYPE> result(getRowsNumber(), getColumnsNumber());
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index)
        {
            for(natural column_index = 0; 
                column_index < getColumnsNumber(); 
                ++column_index)
            {
                result.setElement(-getElement(row_index, column_index),
                                  row_index,
                                  column_index);
            }
        }
        return result;
    }
    
    Matrix<CUSTOM_TYPE> operator-(const Matrix<CUSTOM_TYPE> &operand) const
    {
        return operator+(-operand);
    }
    
    bool isEmpty() const
    {
        return getRowsNumber() == 0 || getColumnsNumber() == 0;
    }
    
    bool isNull() const
    {
        return getRowsNumber() == 0 && getColumnsNumber() == 0;
    }
    
    bool isSquare() const
    {
        return getRowsNumber() == getColumnsNumber();
    }
    
    bool isZeroMatrix() const
    {
        if(isEmpty())
        {
            return false;
        }
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index)
        {
            for(natural column_index = 0; 
                column_index < getColumnsNumber(); 
                ++column_index)
            {
                if(getElement(row_index, column_index) != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool operator==(const Matrix<CUSTOM_TYPE> &operand) const
    {
        if(!haveSameSize(operand))
        {
            return false;
        }
        if(this == &operand)
        {
            return true;
        }
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index)
        {
            for(natural column_index = 0; 
                column_index < getColumnsNumber(); 
                ++column_index)
            {
                if(getElement(row_index, column_index) != 
                        operand.getElement(row_index, column_index))
                {
                    return false;
                }
            }
        }
        return true;
    }
private:
    natural rows_number_;
    natural columns_number_;
    vector<vector<CUSTOM_TYPE> > elements_;
    
    bool haveSameSize(const Matrix<CUSTOM_TYPE>& operand) const
    {
        if(getRowsNumber()      == operand.getRowsNumber()      && 
           getColumnsNumber()   == operand.getColumnsNumber()   )
        {
            return true;
        }
        return false;
    }
    
    bool isMultiplyPossibleWith(const Matrix<CUSTOM_TYPE>& matrix_operand) const
    {
        return getColumnsNumber() == matrix_operand.getRowsNumber();
    }
    
    bool isElementIndexInRange(const natural row_number, 
                               const natural column_number) const
    {
        return isRowIndexInRange(row_number) &&
               isColumnIndexInRange(column_number);
    }
    
    bool isRowIndexInRange(const natural row_number) const
    {
        return row_number       < getRowsNumber() &&
               row_number       >= 0;
    }
    
    bool isColumnIndexInRange(const natural column_number) const
    {
        return column_number    < getColumnsNumber() &&
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
    
    vector<CUSTOM_TYPE> getRowVector(const natural row_number) const
    {
        vector<CUSTOM_TYPE> result;
        if(row_number < 0 || row_number >= getRowsNumber())
        {
            return result;
        }
        for(natural column_index = 0; 
            column_index < getColumnsNumber(); 
            ++column_index)
        {
            result.push_back(getElement(row_number, column_index));
        }
        return result;
    }
    
    vector<CUSTOM_TYPE> getColumnVector(const natural column_number) const
    {
        vector<CUSTOM_TYPE> result;
        if(column_number < 0 || column_number >= getColumnsNumber())
        {
            return result;
        }
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index)
        {
            result.push_back(getElement(row_index, column_number));
        }
        return result;
    }
    
    Matrix<CUSTOM_TYPE> getNullMatrix() const
    {
        return Matrix<CUSTOM_TYPE>();
    }
    
};

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

#endif	/* MATRIX_H */

