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
    void setColumnsNumber(const natural columns_number)
    {
        
    }
    natural getColumnsNumber() const
    {
        return elements_.at(0).size();
    }
    void setRowsNumber(const natural rows_number)
    {
        natural old_rows_number = getRowsNumber();
        elements_.resize(rows_number);
        typename std::vector<std::vector<CUSTOM_TYPE> >::iterator i;
        for(i = elements_.begin() + old_rows_number; i != elements_.end(); ++i)
        {
            (*i).resize(getColumnsNumber());
        }
    }
private:
    std::vector<std::vector<CUSTOM_TYPE> > elements_;
};

#endif	/* MATRIX_H */

