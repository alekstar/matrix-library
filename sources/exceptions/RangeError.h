#ifndef MATRIXRANGEERROR_H
#define	MATRIXRANGEERROR_H
#include <string>
#include <stdexcept>

namespace MatrixExceptions
{
    class RangeError: public std::out_of_range {
    public:
        RangeError(const std::string& message);
    };
}

#endif	/* MATRIXRANGEERROR_H */
