#include "DeterminantIsZero.h"
using namespace MatrixExceptions;

DeterminantIsZero::DeterminantIsZero()
    :logic_error("Determinant of matrix is zero.")
{}

DeterminantIsZero::DeterminantIsZero(const std::string& message)
    :logic_error(message)
{}

