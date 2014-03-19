#include "ColumnIndexOutOfRange.h"
#include "RangeError.h"

using namespace MatrixExceptions;

ColumnIndexOutOfRange::ColumnIndexOutOfRange()
    :RangeError("Index of column is out of range.")
{}
