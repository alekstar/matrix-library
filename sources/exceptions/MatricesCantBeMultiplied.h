#ifndef MATRICESCANTBEMULTIPLIED_H
#define	MATRICESCANTBEMULTIPLIED_H
#include "MathOperationsError.h"

namespace MatrixExceptions
{
    class MatricesCantBeMultiplied: public MathOperationsError
    {
    public:
        MatricesCantBeMultiplied();
    };
}

#endif	/* MATRICESCANTBEMULTIPLIED_H */
