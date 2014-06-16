#include "MatrixAlgorithms.h"
#include "ClassicDeterminantCalculator.h"
#include <cmath>

namespace MatrixAlgorithms
{
    Matrix<double> getUpperTriangularMatrix(const Matrix<double> &matrix) 
        throw(MatrixIsNotSquare)
    {
        if(!isSquare(matrix))
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
        if(!isSquare(matrix))
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
    
    double calculateDeterminant(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare)
    {
        return ClassicDeterminantCalculator().calculate(matrix);
    }
    int defineSignForElement(const natural row_index,
                             const natural column_index) 
    {
        return pow(-1, (row_index + 1 + column_index + 1));
    }
    
    Matrix<double> getMatrixOfAlgebraicAdditions(const Matrix<double>& matrix)
    {
        Matrix<double> result(matrix.getRowsNumber(), 
                              matrix.getColumnsNumber());
        for(natural row_index = 0; 
            row_index < result.getRowsNumber(); 
            ++row_index)
        {
            for(natural column_index = 0;
                column_index < result.getColumnsNumber();
                ++column_index)
            {
                result.at(row_index, column_index) = 
                    defineSignForElement(row_index, column_index) * 
                    calculateDeterminant(
                            getMinorMatrixForElement(matrix,
                                                     row_index, 
                                                     column_index));
            }
        }
        
        return result;
    }
    
    Matrix<double> getInvertedMatrix(const Matrix<double>& matrix)
    {
        double determinant = calculateDeterminant(matrix);
        Matrix<double> matrix_of_algebraic_additions = 
            getMatrixOfAlgebraicAdditions(matrix);
        Matrix<double> inverted_matrix = 
            transpose(matrix_of_algebraic_additions) * (1 / determinant);
        
        return inverted_matrix;
    }
    
    Matrix<double> getIdentityMatrix(const natural size)
    {
        Matrix<double> matrix(size, size);
        for(natural diagonal_index = 0; diagonal_index < size; ++diagonal_index)
        {
            matrix.at(diagonal_index, diagonal_index) = 1;
        }
        return matrix;
    }
}
