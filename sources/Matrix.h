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
#include "exceptions/RowIndexOutOfRange.h"
#include "exceptions/ColumnIndexOutOfRange.h"
#include "exceptions/MatricesCantBeMultiplied.h"
#include "exceptions/MatricesCantBeAddedOrSubstracted.h"
using namespace MatrixExceptions;

template<typename ELEMENT_TYPE>
class Matrix {
    
    FRIEND_TEST(MatrixConstructor, DefaultConstructor);
    FRIEND_TEST(MatrixConstructor, DefaultMatrix1x1);
    FRIEND_TEST(MatrixConstructor, DefaultMatrix2x2);
    FRIEND_TEST(MatrixSetRowsNumber, set3RowsForNewMatrix);
    FRIEND_TEST(MatrixIsElementIndexInRange, TestCase);
    FRIEND_TEST(MatrixSetElement, SomeRandomElementsInMatrix3x4);
    FRIEND_TEST(MatrixSetColumnsNumber, set3ColumnsForMatrix2x2);
    FRIEND_TEST(MatrixSetColumnsNumber, 
                set3ColumnsForMatrix2x2WithNotZeroElements);
    FRIEND_TEST(MatrixGetElementsToCopyFromVector, AllCases);
    FRIEND_TEST(MatrixIsMultiplyPossible, AllCasesWithVector);
    FRIEND_TEST(MatrixGetRowVector, Matrix0x0);
    FRIEND_TEST(MatrixGetRowVector, Matrix1x1);
    FRIEND_TEST(MatrixGetRowVector, Matrix2x2);
    FRIEND_TEST(MatrixHaveSameSize, AllCases);
public:
    typedef typename vector<vector<ELEMENT_TYPE> >::iterator RowsIterator;
    typedef typename vector<ELEMENT_TYPE>::const_iterator VectorConstIterator;
    
    Matrix(const natural rows_number          = 0, 
           const natural columns_number       = 0, 
           const ELEMENT_TYPE initialize_value = 0)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber       (rows_number,       initialize_value);
        setColumnsNumber    (columns_number,    initialize_value);
    }
    
    Matrix(const natural rows_number, 
           const natural columns_number, 
           const vector<ELEMENT_TYPE>& elements,
           const ELEMENT_TYPE initialize_value = 0)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber       (rows_number,       initialize_value);
        setColumnsNumber    (columns_number,    initialize_value);
        setElementsFromVector(elements);
    }
    
    Matrix(const vector<ELEMENT_TYPE> &vector_to_convert)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber(vector_to_convert.size());
        setColumnsNumber(1);
        setElementsFromVector(vector_to_convert);
    }
    
    void setColumnsNumber(const natural columns_number,
                                  const ELEMENT_TYPE initialize_value = 0)
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
    
    template<typename OPERAND_ELEMENT_TYPE>
    Matrix(const Matrix<OPERAND_ELEMENT_TYPE> &operand)
    {
        setRowsNumber(operand.getRowsNumber());
        setColumnsNumber(operand.getColumnsNumber());
        for(natural row_index = 0;
            row_index < getRowsNumber();
            ++row_index)
        {
            for(natural column_index = 0;
                column_index < getColumnsNumber();
                ++column_index)
            {
                setElement(operand.getElement(row_index, column_index), 
                           row_index, 
                           column_index);
            }
        }
    }
    
    natural getColumnsNumber() const
    {   
        return columns_number_;
    }
    
    void setRowsNumber(const natural rows_number,
                       const ELEMENT_TYPE initialize_value = 0)
    {
        elements_.resize(rows_number, 
                         vector<ELEMENT_TYPE>(getColumnsNumber(), 
                                                  initialize_value));
        rows_number_ = rows_number;
    }
    
    natural getRowsNumber() const
    {
        return rows_number_;
    }
    
    template<typename VALUE_TYPE>
    void setElement(const VALUE_TYPE value, 
                    const natural row_index, 
                    const natural column_index) 
            throw(RowIndexOutOfRange, ColumnIndexOutOfRange)
    {
        if(!isRowIndexInRange(row_index))
        {
            throw RowIndexOutOfRange();
        }
        if(!isColumnIndexInRange(column_index))
        {
            throw ColumnIndexOutOfRange();
        }
        if(isElementIndexInRange(row_index, column_index))
        {
            elements_.at(row_index).at(column_index) = value;
        }
    }
    
    ELEMENT_TYPE getElement(const natural row_index, 
                           const natural column_index) const
            throw(RowIndexOutOfRange, ColumnIndexOutOfRange)
    {
        if(!isRowIndexInRange(row_index))
        {
            throw RowIndexOutOfRange();
        }
        if(!isColumnIndexInRange(column_index))
        {
            throw ColumnIndexOutOfRange();
        }
        if(isElementIndexInRange(row_index, column_index))
        {
            return elements_.at(row_index).at(column_index);
        }
    }
    
    template<typename VECTOR_ELEMENT_TYPE>
    void setElementsFromVector(const vector<VECTOR_ELEMENT_TYPE> &elements)
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
        
    Matrix<ELEMENT_TYPE> operator*(const ELEMENT_TYPE value) {
        Matrix<ELEMENT_TYPE> result(getRowsNumber(),
                                         getColumnsNumber());
        for(natural row_index = 0; row_index < getRowsNumber(); ++row_index) {
            for(natural column_index = 0;
                column_index < getColumnsNumber();
                ++column_index) {
                ELEMENT_TYPE current_element =
                    getElement(row_index, column_index);
                result.setElement(current_element * value, 
                                  row_index, 
                                  column_index);
            }
        }

        return result;
    }
    
    Matrix<ELEMENT_TYPE> operator*(const Matrix<ELEMENT_TYPE> &operand) const
        throw(MatricesCantBeMultiplied)
    {
        using VectorMathAlogirthms::makeScalarMultiplication;
        if(!isMultiplyPossibleWith(operand))
        {
            throw MatricesCantBeMultiplied();
        }
        Matrix<ELEMENT_TYPE> result(getRowsNumber(), operand.getColumnsNumber());
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
    
    Matrix<ELEMENT_TYPE> operator+(const Matrix<ELEMENT_TYPE> &operand) const
        throw(MatricesCantBeAddedOrSubstracted)
    {
        if(!haveSameSize(operand))
        {
            throw MatricesCantBeAddedOrSubstracted();
        }
        Matrix<ELEMENT_TYPE> result(getRowsNumber(), getColumnsNumber());
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
    
    Matrix<ELEMENT_TYPE> operator-() const
    {
        Matrix<ELEMENT_TYPE> result(getRowsNumber(), getColumnsNumber());
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
    
    Matrix<ELEMENT_TYPE> operator-(const Matrix<ELEMENT_TYPE> &operand) const
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
    
    bool operator==(const Matrix<ELEMENT_TYPE> &operand) const
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
    vector<vector<ELEMENT_TYPE> > elements_;
    
    bool haveSameSize(const Matrix<ELEMENT_TYPE>& operand) const
    {
        if(getRowsNumber()      == operand.getRowsNumber()      && 
           getColumnsNumber()   == operand.getColumnsNumber()   )
        {
            return true;
        }
        return false;
    }
    
    bool isMultiplyPossibleWith(const Matrix<ELEMENT_TYPE>& matrix_operand) const
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
    
    vector<ELEMENT_TYPE> getRowVector(const natural row_number) const
    {
        vector<ELEMENT_TYPE> result;
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
    
    vector<ELEMENT_TYPE> getColumnVector(const natural column_number) const
    {
        vector<ELEMENT_TYPE> result;
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
    
    Matrix<ELEMENT_TYPE> getNullMatrix() const
    {
        return Matrix<ELEMENT_TYPE>();
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

