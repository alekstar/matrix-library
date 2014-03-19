#include <stdexcept>

#include "RangeError.h"
using namespace MatrixExceptions;

RangeError::RangeError(const std::string& message)
    :out_of_range(message)
{}
