#ifndef MATRIXISNOTSQUARE_H
#define	MATRIXISNOTSQUARE_H
#include <stdexcept>

namespace MatrixExceptions
{
    class MatrixIsNotSquare : public std::logic_error{
    public:
        MatrixIsNotSquare();
    private:

    };
}

#endif	/* MATRIXISNOTSQUARE_H */
