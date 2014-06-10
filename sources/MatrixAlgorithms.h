#ifndef MATRIXALGORITHMS_H
#define	MATRIXALGORITHMS_H

#include <vector>

#include "Matrix.h"
#include "exceptions/MatrixIsNotSquare.h"
#include "VectorMathAlgorithms.h"
#include "natural_type.h"

namespace MatrixAlgorithms
{
    using namespace VectorMathAlogirthms;
    using namespace MatrixExceptions;
    
    const double DETERMINANT_OF_MATRIX_0X0 = 1.0;
    const double DETERMINANT_OF_MATRIX_WITH_ZERO_ROWS_OR_COLUMNS = 0.0;
    
    template <typename ELEMENT_TYPE>
    bool haveZeroRows(const Matrix<ELEMENT_TYPE> &matrix) 
    {
        for(natural row_index = 0;
            row_index < matrix.getRowsNumber();
            ++row_index) 
        {
            if(vectorHaveOnlyZeros(getRowVector(matrix, row_index)))
            {
                return true;
            };
        }
        return false;
    }
    
    template <typename ELEMENT_TYPE>
    bool haveZeroColumns(const Matrix<ELEMENT_TYPE> &matrix)
    {
        for(natural column_index = 0;
            column_index < matrix.getRowsNumber();
            ++column_index) 
        {
            if(vectorHaveOnlyZeros(getColumnVector(matrix, column_index)))
            {
                return true;
            };
        }
        return false;
    }
    
    Matrix<double> getUpperTriangularMatrix(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);

    double calculateDeterminantViaTriangularMatrix(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);
    
    template <typename ELEMENT_TYPE>
    Matrix<ELEMENT_TYPE> transpose(const Matrix<ELEMENT_TYPE>& operand)
    {
        Matrix<ELEMENT_TYPE> result(operand.getColumnsNumber(), 
                                    operand.getRowsNumber());
        for(natural row_index = 0;
            row_index < result.getRowsNumber();
            ++row_index)
        {
            for(natural column_index = 0;
                column_index < result.getColumnsNumber();
                ++column_index)
            {
                result.at(row_index, column_index) = 
                    operand.at(column_index, row_index);
            }
        }
        return result;
    }
    
    double calculateDeterminant(const Matrix<double> &matrix)
       throw(MatrixIsNotSquare);
}

#endif	/* MATRIXALGORITHMS_H */
