#ifndef MATRIXRANGEERROR_H
#define	MATRIXRANGEERROR_H
#include <string>
#include <stdexcept>

class MatrixRangeError: public std::out_of_range {
public:
    MatrixRangeError(const std::string& message);
};

#endif	/* MATRIXRANGEERROR_H */
