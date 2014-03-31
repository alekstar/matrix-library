#ifndef VECTORMATHALGORITHMS_H
#define	VECTORMATHALGORITHMS_H
#include <vector>
#include <algorithm>
namespace VectorMathAlogirthms
{
    template<typename CUSTOM_TYPE>
    CUSTOM_TYPE makeScalarMultiplication(
        const std::vector<CUSTOM_TYPE> &left,
        const std::vector<CUSTOM_TYPE> &right)
    {
        CUSTOM_TYPE result = 0;
        if(left.size() != right.size())
        {
            return result;
        }
        typename std::vector<CUSTOM_TYPE>::const_iterator left_index;
        typename std::vector<CUSTOM_TYPE>::const_iterator right_index;
        for(left_index = left.begin(), right_index = right.begin();
            left_index < left.end() && right_index < right.end();
            ++left_index, ++right_index)
        {
            result += (*left_index)*(*right_index);
        }
        return result;
    }
    
    bool isNotZero(int i);
    bool vectorHaveOnlyZeros(const std::vector<int>& operand);
}

#endif	/* VECTORMATHALGORITHMS_H */

