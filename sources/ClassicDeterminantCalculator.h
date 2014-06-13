#ifndef CLASSICDETERMINANTCALCULATOR_H
#define	CLASSICDETERMINANTCALCULATOR_H
#include "Matrix.h"
#include "exceptions/MatrixIsNotSquare.h"
#include <gtest/gtest_prod.h>

class ClassicDeterminantCalculator
{
public:

    double calculate(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);
};
#endif	/* CLASSICDETERMINANTCALCULATOR_H */
