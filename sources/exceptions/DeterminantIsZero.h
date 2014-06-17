#ifndef DETERMINANTISZERO_H
#define	DETERMINANTISZERO_H
#include <stdexcept>
#include <string>

namespace MatrixExceptions
{
    class DeterminantIsZero : public std::logic_error
    {
    public:
        DeterminantIsZero();
        DeterminantIsZero(const std::string& message);
    };
}

#endif	/* DETERMINANTISZERO_H */

