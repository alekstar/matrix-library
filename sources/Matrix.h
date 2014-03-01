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
    Matrix(natural rows_number          = 0, 
           natural columns_number       = 0, 
           CUSTOM_TYPE initialize_value = 0)
    {
        elements_.resize(rows_number);
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
private:
    std::vector<std::vector<CUSTOM_TYPE> > elements_;
};

#endif	/* MATRIX_H */

