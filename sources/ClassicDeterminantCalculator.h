#ifndef CLASSICDETERMINANTCALCULATOR_H
#define	CLASSICDETERMINANTCALCULATOR_H
#include "Matrix.h"
#include "exceptions/MatrixIsNotSquare.h"
#include <gtest/gtest_prod.h>


class ClassicDeterminantCalculator
{
    FRIEND_TEST(DefineSignForElement, SeveralCases);
public:

    double calculate(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);
private:
    int defineSignForElement(natural row_index, 
                             natural column_index);
};
#endif	/* CLASSICDETERMINANTCALCULATOR_H */

