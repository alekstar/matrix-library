#ifndef CLASSICDETERMINANTCALCULATOR_H
#define	CLASSICDETERMINANTCALCULATOR_H
#include "Matrix.h"
#include "exceptions/MatrixIsNotSquare.h"
#include <gtest/gtest_prod.h>


class ClassicDeterminantCalculator
{
    FRIEND_TEST(DefineSignForElement, SeveralCases);
    FRIEND_TEST(GetMinor, Minor0x0FromMatrix3x3);
    FRIEND_TEST(GetMinor, Minor1x1FromMatrix3x3);
    FRIEND_TEST(GetMinor, Minor0x1FromMatrix3x3);
public:

    double calculate(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);
private:
    int defineSignForElement(natural row_index, 
                             natural column_index);
    template<typename ELEMENT_TYPE>
    Matrix<ELEMENT_TYPE> getMinorForElement(Matrix<ELEMENT_TYPE>& matrix,
                                             natural row_index, 
                                             natural column_index)
    {
        if(isNull(matrix))
        {
            return Matrix<ELEMENT_TYPE>(0, 0);
        }
        matrix.throwExceptionIfColumnIndexIsWrong(column_index);
        matrix.throwExceptionIfRowIndexIsWrong(row_index);
        Matrix<ELEMENT_TYPE> minor(matrix.getRowsNumber()       - 1, 
                                   matrix.getColumnsNumber()    - 1);
        for(natural matrix_row_index = 0,
            minor_row_index = 0; 
            matrix_row_index < matrix.getRowsNumber();
            ++matrix_row_index)
        {
            if(matrix_row_index == row_index)
            {
                continue;
            }
            for(natural matrix_column_index = 0,
                minor_column_index = 0;
                matrix_column_index < matrix.getColumnsNumber();
                ++matrix_column_index)
            {
                if(matrix_column_index == column_index)
                {
                    continue;
                }
                minor.at(minor_row_index,
                         minor_column_index) = matrix.at(matrix_row_index,
                                                         matrix_column_index);
                ++minor_column_index;
            }
            ++minor_row_index;
        }
        
        return minor;
    }
};
#endif	/* CLASSICDETERMINANTCALCULATOR_H */
