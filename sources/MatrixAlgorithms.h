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
    
    template <typename ELEMENT_TYPE>
    bool haveZeroRows(const Matrix<ELEMENT_TYPE> &matrix) 
    {
        for(natural row_index = 0;
            row_index < matrix.getRowsNumber();
            ++row_index) 
        {
            if(vectorHaveOnlyZeros(matrix.getRowVector(row_index)));
        }
    }
    
    Matrix<double> getUpperTriangularMatrix(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);

    double calculateDeterminantViaTriangularMatrix(const Matrix<double> &matrix)
        throw(MatrixIsNotSquare);
}

#endif	/* MATRIXALGORITHMS_H */
