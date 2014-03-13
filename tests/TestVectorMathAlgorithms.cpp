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
    std::vector<int> result = 
        vectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                       vector2);
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(3, result.at(0));
    EXPECT_EQ(8, result.at(1));
}

TEST(TestMakeScalarMultiplication, TwoVectorsWithNoneElements)
{
    std::vector<int> vector1;
    std::vector<int> vector2;
    std::vector<int> result = 
        vectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                       vector2);
    EXPECT_EQ(0, result.size());
}

TEST(TestMakeScalarMultiplication, TwoVectorsWithDifferentNumberOfElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);
    std::vector<int> result = 
        vectorMathAlogirthms::makeScalarMultiplication(vector1,
                                                       vector2);
    EXPECT_EQ(0, result.size());
}
