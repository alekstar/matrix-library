#ifndef MATRIXROWINDEXOUTOFRANGE_H
#define	MATRIXROWINDEXOUTOFRANGE_H
#include "RangeError.h"

namespace MatrixExceptions
{
    class RowIndexOutOfRange: public RangeError
    {
    public:
        RowIndexOutOfRange();
    };
}

#endif	/* MATRIXROWINDEXOUTOFRANGE_H */
