#include "pch.h"
#include "../Maths/Vector3.h"
#include <iostream>

TEST(Vector3_Constructor, AssignsAllComponents) {
    Vector3 v(3, 4, 5);
    EXPECT_EQ(v.x, 3);
    EXPECT_EQ(v.y, 4);
    EXPECT_EQ(v.z, 5);
}

// ==
TEST(Vector3_EqualityComparison, Returns_True_For_Equal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) ==  Vector3(3, 4, 5));
}

// Unit Tests
// Test-Driven Development (First write the test, then the function, then clean up your code)

// !=
TEST(Vector3_EqualityComparison, Returns_False_For_Inequal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(2, 4, 5));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 2, 5));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 4, 2));
    EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(2, 2, 2));
}

// -
TEST(Vector3_Negate, InvertsPositiveValues) {
    auto result = -Vector3(3, 4, 5);
    EXPECT_EQ(result.x, -3);
    EXPECT_EQ(result.y, -4);
    EXPECT_EQ(result.z, -5);
}

// *
TEST(Vector3_Scaler, Multiply_Vectors) {
    Vector3 result = Vector3(3, 4, 2) * Vector3(6, 7, 8);
    EXPECT_EQ(result.x, 18);
    EXPECT_EQ(result.y, 28);
    EXPECT_EQ(result.z, 16);
}

// /
TEST(Vector3_Division, Divide_Vectors) {
    auto result = Vector3(4, 4, 12) / 2;
    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, 2);
    EXPECT_EQ(result.z, 6);
}

// +
TEST(Vector3_Addition, Adding_Vectors) {
    auto result = Vector3(3, 4, 5) + Vector3(7, 6, 5);
    EXPECT_EQ(result.x, 10);
    EXPECT_EQ(result.y, 10);
    EXPECT_EQ(result.z, 10);
}

// -
TEST(Vector3_Subtraction, Subtracting_Vectors) {
    auto result = Vector3(7, 2, 4) - Vector3(7, 1, 5);
    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 1);
    EXPECT_EQ(result.z, -1);
}

// Magnitude
TEST(Vector3_Magnitude, Magnitude_Vector) {
    EXPECT_FLOAT_EQ(Vector3(2, 2, 1).magnitude(), 3);
}

// Normalize
TEST(Vector3_Normalize, Normalize_Vector) {
    EXPECT_FLOAT_EQ(Vector3(2, 2, 1).normalize().x , (2.0 / 3.0));
    EXPECT_FLOAT_EQ(Vector3(2, 2, 1).normalize().y , (2.0 / 3.0));
    EXPECT_FLOAT_EQ(Vector3(2, 2, 1).normalize().z , (1.0 / 3.0));
}

//SquareUP
TEST(Vector_Square, Square_Magnitude) {
    EXPECT_FLOAT_EQ(Vector3(1, 2, 2).squareMagnitude(), 9 );
}

//Dot
TEST(Vector_Dot, Ressult_of_Dot_Vectors)
{
    ASSERT_EQ(Vector3::Dot(Vector3(1, 2, 3), Vector3(4, 5, 6)), 32 );
}

//Cross
TEST(Vector_Cross, Result_of_New_Vector)
{
    ASSERT_EQ(Vector3::Cross(Vector3(1, 2, 3), Vector3(4, 5, 6)), Vector3(-3, 6, -3));
}

//Distance
TEST(Vector_Distance, Result_of_float_distance_of_Vectors) {
    EXPECT_FLOAT_EQ(Vector3::Distance(Vector3(1, 2, 3), Vector3(4, 5, 6)), sqrt(27));
}