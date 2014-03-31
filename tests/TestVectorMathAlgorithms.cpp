#include <gtest/gtest.h>
#include "sources/VectorMathAlgorithms.h"

using namespace VectorMathAlogirthms;

TEST(MakeScalarMultiplication, TwoVectorsWithTwoElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(2);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);
    EXPECT_EQ(11, makeScalarMultiplication(vector1,
                                           vector2));
}

TEST(MakeScalarMultiplication, TwoVectorsWithNoneElements)
{
    std::vector<int> vector1;
    std::vector<int> vector2;
    EXPECT_EQ(0, makeScalarMultiplication(vector1,
                                          vector2));
}

TEST(MakeScalarMultiplication, TwoVectorsWithDifferentNumberOfElements)
{
    std::vector<int> vector1;
    vector1.push_back(1);
    std::vector<int> vector2;
    vector2.push_back(3);
    vector2.push_back(4);        
    EXPECT_EQ(0, makeScalarMultiplication(vector1,
                                          vector2));
}

TEST(VectorHaveOnlyZeros, VectorWithOnlyZeros)
{
    std::vector<int> vector_with_only_zeros(10, 0);
    EXPECT_TRUE(vectorHaveOnlyZeros(vector_with_only_zeros));
}

TEST(VectorHaveOnlyZeros, VectorWithNotOnlyZeros)
{
    std::vector<int> vector_with_not_only_zeros;
    vector_with_not_only_zeros.push_back(1);
    vector_with_not_only_zeros.push_back(0);
    vector_with_not_only_zeros.push_back(0);
    vector_with_not_only_zeros.push_back(0);
    vector_with_not_only_zeros.push_back(2);
    EXPECT_FALSE(vectorHaveOnlyZeros(vector_with_not_only_zeros));
}
