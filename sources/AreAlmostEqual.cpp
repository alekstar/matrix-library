#include "AreAlmostEqual.h"
#include <limits>
#include <cmath>

bool areAlmostEqual(const double operand1, const double operand2)
{
    return fabs(operand1 - operand2) < std::numeric_limits<double>::epsilon();
}
