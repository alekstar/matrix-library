#ifndef MATHOPERATIONSERROR_H
#define	MATHOPERATIONSERROR_H
#include <stdexcept>
#include <string>

namespace MatrixExceptions
{
    class MathOperationsError : public std::logic_error 
    {
    public:
        MathOperationsError(const std::string& message);
    };
}

#endif	/* MATHOPERATIONSERROR_H */

