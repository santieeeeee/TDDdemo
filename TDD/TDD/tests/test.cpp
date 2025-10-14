#include <gtest/gtest.h>
#include "../MathExpression.h"

TEST(MathExpression, Constructor) {
	string expression = "1";
	MathExpression a(expression);
	
	EXPECT_EQ(a.getExpression(), expression);
}

TEST(MathExpression, setExpression) {
	MathExpression a("a+b");
	string expression = "x-y/z";
	a.setExpression(expression);

	EXPECT_EQ(a.getExpression(), expression);
}

TEST(MathExpression, getExpression) {
	MathExpression a("");

	EXPECT_EQ(a.getExpression(), "");

	string expression = "a*b-c";
	a.setExpression(expression);

	EXPECT_EQ(a.getExpression(), expression);
}

TEST(MathExpression, calculate_EmptyExpression) {
	MathExpression a("");

	EXPECT_THROW(a.calculate(), invalid_argument);
}

TEST(MathExpression, calculate_SingleNumber_5) {
	MathExpression a("5");

	EXPECT_EQ(a.calculate(), 5);
}

TEST(MathExpression, calculate_SingleNumber_9) {
	MathExpression a("9");

	EXPECT_EQ(a.calculate(), 9);
}

TEST(MathExpression, calculate_SingleNumber_minus_382) {
	MathExpression a("-382");

	EXPECT_EQ(a.calculate(), -382);
}

TEST(MathExpression, calculate_SingleNumber_0) {
	MathExpression a("0");

	EXPECT_EQ(a.calculate(), 0);
}

TEST(MathExpression, calculate_Expression_1_plus_1) {
	MathExpression a("1+1");

	EXPECT_EQ(a.calculate(), 2);
}

TEST(MathExpression, calculate_Expression_123_plus_321) {
	MathExpression a("123+321");

	EXPECT_EQ(a.calculate(), 444);
}