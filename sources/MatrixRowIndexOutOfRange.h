#ifndef MATRIXROWINDEXOUTOFRANGE_H
#define	MATRIXROWINDEXOUTOFRANGE_H
#include <stdexcept>
#include "natural_type.h"

class MatrixRowIndexOutOfRange: public std::out_of_range
{
public:
    MatrixRowIndexOutOfRange();
};

#endif	/* MATRIXROWINDEXOUTOFRANGE_H */

