#include "MathOperationsError.h"
using namespace MatrixExceptions;

MathOperationsError::MathOperationsError(const std::string& message)
    :logic_error(message)
{}
