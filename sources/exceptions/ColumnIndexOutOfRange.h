#ifndef MATRIXCOLUMNINDEXOUTOFRANGE_H
#define	MATRIXCOLUMNINDEXOUTOFRANGE_H
#include "RangeError.h"

namespace MatrixExceptions
{
    class ColumnIndexOutOfRange: public RangeError 
    {
    public:
        ColumnIndexOutOfRange();
    };
}
#endif	/* MATRIXCOLUMNINDEXOUTOFRANGE_H */
