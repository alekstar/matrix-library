#include <limits>
#include <cmath>
#include "Matrix.h"

template<>
bool operator==<double>(const Matrix<double>& left_operand,
                        const Matrix<double>& right_operand)
{
    if(!haveSameSize(left_operand, right_operand))
    {
        return false;
    }
    if(&left_operand == &right_operand)
    {
        return true;
    }
    for(natural row_index = 0; 
        row_index < left_operand.getRowsNumber();
        ++row_index)
    {
        for(natural column_index = 0;
            column_index < left_operand.getColumnsNumber();
            ++column_index)
        {
            if(fabs(left_operand.at(row_index, column_index) - 
                        right_operand.at(row_index, column_index)) >= 
                            std::numeric_limits<double>::epsilon())
            {
                return false;
            }
        }
    }
    return true;
}
