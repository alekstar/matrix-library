#ifndef MATRIXALGORITHMS_H
#define	MATRIXALGORITHMS_H

#include <vector>

#include "Matrix.h"
#include "exceptions/MatrixIsNotSquare.h"
#include "VectorMathAlgorithms.h"
#include "natural_type.h"
#include "exceptions/WrongSize.h"

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
    int defineSignForElement(natural row_index, 
                             natural column_index);
    
    template<typename ELEMENT_TYPE>
    Matrix<ELEMENT_TYPE> getMinorMatrixForElement(
            const Matrix<ELEMENT_TYPE>& matrix,
            natural row_index, 
            natural column_index)
    {
        matrix.throwExceptionIfColumnIndexIsWrong(column_index);
        matrix.throwExceptionIfRowIndexIsWrong(row_index);
        if(!isSquare(matrix))
        {
            throw MatrixIsNotSquare();
        }
        if(isNull(matrix) || 
           (matrix.getRowsNumber() == 1 && matrix.getColumnsNumber() == 1))
        {
            return Matrix<ELEMENT_TYPE>(0, 0);
        }
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
    
    Matrix<double> getMatrixOfAlgebraicAdditions(const Matrix<double>& matrix);
    Matrix<double> getInvertedMatrix(const Matrix<double>& matrix);
    Matrix<double> getIdentityMatrix(const natural size)
        throw(WrongSize);
}

#endif	/* MATRIXALGORITHMS_H */
