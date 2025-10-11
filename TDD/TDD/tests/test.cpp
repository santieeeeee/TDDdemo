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