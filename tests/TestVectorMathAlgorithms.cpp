#include <gtest/gtest.h>
#include "sources/VectorMathAlgorithms.h"

TEST(TestMakeScalarMultiplication, TwoVectorsWithTwoElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(2);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);
    EXPECT_EQ(11, vectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                                vector2));
}

TEST(TestMakeScalarMultiplication, TwoVectorsWithNoneElements)
{
    std::vector<int> vector1;
    std::vector<int> vector2;
    EXPECT_EQ(0, vectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                                vector2));
}

TEST(TestMakeScalarMultiplication, TwoVectorsWithDifferentNumberOfElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);        
    EXPECT_EQ(0, vectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                                vector2));
}
