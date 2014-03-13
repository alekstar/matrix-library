#ifndef VECTORMATHALGORITHMS_H
#define	VECTORMATHALGORITHMS_H
#include <vector>

namespace vectorMathAlogirthms
{
    template<typename CUSTOM_TYPE>
    std::vector<CUSTOM_TYPE> makeScalarMultiplication(
        const std::vector<CUSTOM_TYPE> &left,
        const std::vector<CUSTOM_TYPE> &right)
    {
        std::vector<CUSTOM_TYPE> result;
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
            result.push_back((*left_index)*(*right_index));
        }
    }
}

#endif	/* VECTORMATHALGORITHMS_H */

