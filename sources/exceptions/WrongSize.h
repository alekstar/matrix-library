#ifndef WRONGSIZE_H
#define	WRONGSIZE_H
#include <stdexcept>
#include <string>

namespace MatrixExceptions
{
    class WrongSize : public std::logic_error
    {
    public:
        WrongSize();
        WrongSize(const std::string& message);
    };
}

#endif	/* WRONGSIZE_H */

