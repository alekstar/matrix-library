#include "MatrixAlgorithms.h"

namespace MatrixAlgorithms
{
    const double DETERMINANT_OF_MATRIX_0X0 = 1.0;
    const double DETERMINANT_OF_MATRIX_WITH_ZERO_ROWS_OR_COLUMNS = 0.0;
    Matrix<double> getUpperTriangularMatrix(const Matrix<double> &matrix) 
        throw(MatrixIsNotSquare)
    {
        if(!matrix.isSquare())
        {
            throw MatrixIsNotSquare();
        }
        Matrix<double> result = matrix;
        for(natural outer_column_index = 0;
            outer_column_index < matrix.getColumnsNumber() - 1;
            ++outer_column_index)
        {
            for(natural row_index = outer_column_index + 1;
                row_index < matrix.getRowsNumber();
                ++row_index)
            {
                double value_to_divide_row = 
                    result.getElement(row_index, outer_column_index) / 
                    result.getElement(outer_column_index, outer_column_index);
                for(natural inner_column_index = 0;
                    inner_column_index < matrix.getColumnsNumber();
                    ++inner_column_index)
                {   

                    double value_to_substract = 
                        result.getElement(outer_column_index, 
                                          inner_column_index) * 
                        value_to_divide_row;
                    double current_element_value =
                        result.getElement(row_index, inner_column_index) - 
                        value_to_substract;
                    result.setElement(current_element_value,
                                      row_index, inner_column_index);
                }
            }
        }
        return result;
    }

    double calculateDeterminantViaTriangularMatrix(const Matrix<double> &matrix) 
        throw(MatrixIsNotSquare)
    {
        if(!matrix.isSquare())
        {
            throw MatrixIsNotSquare();
        }
        if(haveZeroRows(matrix) || haveZeroColumns(matrix))
        {
            return DETERMINANT_OF_MATRIX_WITH_ZERO_ROWS_OR_COLUMNS;
        }
        if(isNull(matrix))
        {
            return DETERMINANT_OF_MATRIX_0X0;
        }
        Matrix<double> triangular_matrix = getUpperTriangularMatrix(matrix);
        double determinant = 1;
        for(natural diagonal_index = 0; 
            diagonal_index < matrix.getColumnsNumber();
            ++diagonal_index)
        {
            determinant *= 
                triangular_matrix.getElement(diagonal_index, diagonal_index);
        }
        return determinant;
    }
}