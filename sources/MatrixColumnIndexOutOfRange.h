#ifndef MATRIXCOLUMNINDEXOUTOFRANGE_H
#define	MATRIXCOLUMNINDEXOUTOFRANGE_H
#include <stdexcept>

class MatrixColumnIndexOutOfRange: public std::out_of_range {
public:
    MatrixColumnIndexOutOfRange();
};

#endif	/* MATRIXCOLUMNINDEXOUTOFRANGE_H */
