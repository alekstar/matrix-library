#ifndef MATRIX_H
#define	MATRIX_H
#include <vector>
#include <gtest/gtest_prod.h>

typedef std::size_t natural;

template<typename CUSTOM_TYPE>
class Matrix {
    FRIEND_TEST(TestMatrixConstructor, DefaultConstructor);
    FRIEND_TEST(TestMatrixConstructor, DefaultMatrix1x1);
    FRIEND_TEST(TestMatrixConstructor, DefaultMatrix2x2);
    FRIEND_TEST(TestMatrixSetRowsNumber, set3RowsForNewMatrix);
    FRIEND_TEST(TestMatrixIsElementIndexInRange, TestCase);
    FRIEND_TEST(TestMatrixSetElement, SomeRandomElementsInMatrix3x4);
public:
    Matrix(const natural rows_number          = 0, 
           const natural columns_number       = 0, 
           const CUSTOM_TYPE initialize_value = 0)
    {
        setRowsNumber(rows_number);
        typename std::vector<std::vector<CUSTOM_TYPE> >::iterator i;
        for(i = elements_.begin(); i != elements_.end(); ++i)
        {
            (*i).resize(columns_number);
            typename std::vector<CUSTOM_TYPE>::iterator j;
            for(j = (*i).begin(); j != (*i).end(); ++j)
            {
                *j = initialize_value;
            }
        }
    }
    Matrix(const natural rows_number, 
           const natural columns_number, 
           const std::vector<CUSTOM_TYPE> &element_values);
    
    void setColumnsNumber(const natural columns_number,
                          const CUSTOM_TYPE initialize_value = 0)
    {
        typename std::vector<std::vector<CUSTOM_TYPE> >::iterator columns_iterator;
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
                         std::vector<CUSTOM_TYPE>(getColumnsNumber(), 
                                                  initialize_value));
        rows_number_ = rows_number;
    }
    natural getRowsNumber() const
    {
        return elements_.size();
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
    void setElementsFromVector(const std::vector<CUSTOM_TYPE> &element_values);
    void getElementsToVector(std::vector<CUSTOM_TYPE> &elements_vector) const;
    Matrix<CUSTOM_TYPE>& operator*(const CUSTOM_TYPE value);
    Matrix<CUSTOM_TYPE>& operator*(const std::vector<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator*(const Matrix<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator+(const Matrix<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator-(const Matrix<CUSTOM_TYPE> &operand);
    Matrix<CUSTOM_TYPE>& operator==(const Matrix<CUSTOM_TYPE> &operand);
private:
    natural rows_number_;
    natural columns_number_;
    std::vector<std::vector<CUSTOM_TYPE> > elements_;
    bool isElementIndexInRange(const natural row_number, 
                               const natural column_number) const
    {
        return row_number       < getRowsNumber() &&
               row_number       >= 0 &&
               column_number    < getColumnsNumber() &&
               column_number    >= 0;
    }
};

#endif	/* MATRIX_H */

