#include <stdexcept>

#include "MatrixRangeError.h"

MatrixRangeError::MatrixRangeError(const std::string& message)
    :out_of_range(message)
{}
