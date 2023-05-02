// Copyright 2023 Kudryashov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Copy_ComplexNumber) {
    ComplexNumber num1(3.0, 4.0);
    ComplexNumber num2(num1);
    // Assert

    EXPECT_EQ(num1.getRe(), num2.getRe());
    EXPECT_EQ(num1.getIm(), num2.getIm());
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Sum_ComplexNumber) {
    ComplexNumber num1(2.0, 2.0);
    ComplexNumber num2(3.0, 4.0);
    ComplexNumber res = num1 + num2;
    ComplexNumber realRes(5.0, 6.0);

    EXPECT_EQ(res, realRes);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Multiply_ComplexNumber) {
    ComplexNumber num1(2.0, 2.0);
    ComplexNumber num2(3.0, 4.0);
    ComplexNumber res = num1 * num2;
    ComplexNumber realRes(-2, 14);

    EXPECT_EQ(res, realRes);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Get_Im) {
    ComplexNumber z(1.0, 5.0);
    double im = z.getIm();

    EXPECT_EQ(5.0, im);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Set_Re) {
    ComplexNumber z(1.0, 0.0);
    z.setRe(5.0);

    EXPECT_EQ(5.0, z.getRe());
}
