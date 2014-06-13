#include "ClassicDeterminantCalculator.h"
#include "MatrixAlgorithms.h"
#include "natural_type.h"
using namespace MatrixAlgorithms;

double ClassicDeterminantCalculator::
    calculate(const Matrix<double> &matrix)
        throw (MatrixIsNotSquare)
{
    if (!isSquare(matrix))
    {
        throw MatrixIsNotSquare();
    }
    if (haveZeroRows(matrix) || haveZeroColumns(matrix))
    {
        return DETERMINANT_OF_MATRIX_WITH_ZERO_ROWS_OR_COLUMNS;
    }
    if (isNull(matrix))
    {
        return DETERMINANT_OF_MATRIX_0X0;
    }
    if (matrix.getColumnsNumber() == 1 && matrix.getRowsNumber() == 1)
    {
        return matrix.at(0, 0);
    }
    if (matrix.getColumnsNumber() == 2 && matrix.getRowsNumber() == 2)
    {
        return matrix.at(0, 0) * matrix.at(1, 1) -
            matrix.at(0, 1) * matrix.at(1, 0);
    }
    double determinant = 0;
    for(natural column_index = 0;
        column_index < matrix.getColumnsNumber();
        ++column_index)
    {
        int sign = defineSignForElement(0, column_index);
        double current_element = matrix.at(0, column_index);
        Matrix<double> minor = 
            getMinorMatrixForElement(matrix, 0, column_index);
        determinant +=  sign * 
                        current_element * 
                        calculate(minor);
    }
    return determinant;
}
