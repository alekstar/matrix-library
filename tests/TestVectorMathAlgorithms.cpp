#include <gtest/gtest.h>
#include "sources/VectorMathAlgorithms.h"

TEST(MakeScalarMultiplication, TwoVectorsWithTwoElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(2);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);
    EXPECT_EQ(11, VectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                                vector2));
}

TEST(MakeScalarMultiplication, TwoVectorsWithNoneElements)
{
    std::vector<int> vector1;
    std::vector<int> vector2;
    EXPECT_EQ(0, VectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                                vector2));
}

TEST(MakeScalarMultiplication, TwoVectorsWithDifferentNumberOfElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);        
    EXPECT_EQ(0, VectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                                vector2));
}
