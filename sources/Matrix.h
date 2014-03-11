#ifndef MATRIX_H
#define	MATRIX_H
#include <vector>
#include <gtest/gtest_prod.h>
#include <iostream>
#include <iterator>
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
public:
    typedef typename vector<vector<CUSTOM_TYPE> >::iterator RowsIterator;
    
    friend std::ostream& operator<<(std::ostream &result, 
                                    Matrix<CUSTOM_TYPE> matrix)
    {
        std::ostream_iterator<CUSTOM_TYPE> output_stream(result, "\t");
        RowsIterator rows_iterator;
        for(rows_iterator = matrix.elements_.begin();
            rows_iterator != matrix.elements_.end();
            ++rows_iterator)
        {
            std::copy(rows_iterator->begin(), 
                      rows_iterator->end(), 
                      output_stream);
            result << std::endl;
        }
        return result;
    }
    
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
           const vector<CUSTOM_TYPE> &element_values,
           const CUSTOM_TYPE initialize_value = 0)
    {
        rows_number_    = 0;
        columns_number_ = 0;
        setRowsNumber       (rows_number,       initialize_value);
        setColumnsNumber    (columns_number,    initialize_value);
        setElementsFromVector(element_values);
    }
    
    void setColumnsNumber(const natural columns_number,
                          const CUSTOM_TYPE initialize_value = 0)
    {
        typename 
            vector<vector<CUSTOM_TYPE> >::iterator columns_iterator;
        for(columns_iterator = elements_.begin(); 
            columns_iterator != elements_.end(); ++columns_iterator)
        {
            columns_iterator->resize(columns_number, initialize_value);
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
    
    void setElementsFromVector(const vector<CUSTOM_TYPE> &element_values)
    {
        typename vector<CUSTOM_TYPE>::const_iterator vector_iterator = 
            element_values.begin();
        RowsIterator rows_iterator;
        for(rows_iterator = elements_.begin(); 
            rows_iterator != elements_.end();
            rows_iterator++)
        {
            natural elements_to_copy = 
                getNumberOfElementsToCopyFromVector(vector_iterator,
                                                    element_values.end());
            std::copy(vector_iterator, 
                      vector_iterator + elements_to_copy, 
                      rows_iterator->begin());
            vector_iterator += elements_to_copy;
        }
    }
    void getElementsToVector(vector<CUSTOM_TYPE> &elements_vector) const;
    Matrix<CUSTOM_TYPE>& operator*(const CUSTOM_TYPE value);
    Matrix<CUSTOM_TYPE>& operator*(const vector<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator*(const Matrix<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator+(const Matrix<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator-(const Matrix<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator==(const Matrix<CUSTOM_TYPE> &operand);
private:
    natural rows_number_;
    natural columns_number_;
    vector<vector<CUSTOM_TYPE> > elements_;
    
    bool isElementIndexInRange(const natural row_number, 
                               const natural column_number) const
    {
        return row_number       < getRowsNumber() &&
               row_number       >= 0 &&
               column_number    < getColumnsNumber() &&
               column_number    >= 0;
    }
    
    natural getNumberOfElementsToCopyFromVector(
              typename vector<CUSTOM_TYPE>::const_iterator vector_iterator,
              typename vector<CUSTOM_TYPE>::const_iterator vector_end_iterator)
    {
        natural elements_last = vector_end_iterator - vector_iterator;
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

#endif	/* MATRIX_H */

