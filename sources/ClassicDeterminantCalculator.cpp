#include "ClassicDeterminantCalculator.h"
#include <cmath>
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
        return matrix.getElement(0, 0);
    }
    if (matrix.getColumnsNumber() == 2 && matrix.getRowsNumber() == 2)
    {
        return matrix.getElement(0, 0) * matrix.getElement(1, 1) -
            matrix.getElement(0, 1) * matrix.getElement(1, 0);
    }
}

int ClassicDeterminantCalculator::
    defineSignForElement(const natural row_index,
                         const natural column_index)
{
    int result = 1;
    for (natural internal_row_index = 0;
        internal_row_index <= row_index;
        ++internal_row_index)
    {
        int first_element_sign = pow(-1, internal_row_index);
        for (natural internal_column_index = 0;
            internal_column_index <= column_index;
            ++internal_column_index)
        {
            result = first_element_sign * pow(-1, internal_column_index);
        }
    }
    return result;
}