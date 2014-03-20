#ifndef MATRICESCANTBEADDEDORSUBSTRACTED_H
#define	MATRICESCANTBEADDEDORSUBSTRACTED_H
#include "MathOperationsError.h"

namespace MatrixExceptions
{
    class MatricesCantBeAddedOrSubstracted : public MathOperationsError {
    public:
        MatricesCantBeAddedOrSubstracted();
    };
}

#endif	/* MATRICESCANTBEADDEDORSUBSTRACTED_H */

