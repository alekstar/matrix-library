#include "VectorMathAlgorithms.h"
#include <vector>

namespace VectorMathAlogirthms
{
    bool isNotZero(int i) 
    {
        return i != 0;
    }

    bool vectorHaveOnlyZeros(const std::vector<int>& operand) 
    {
        return std::count(operand.begin(),
                          operand.end(),
                          0) == operand.size();
    }
}
    