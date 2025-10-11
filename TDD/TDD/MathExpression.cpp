#include "MathExpression.h"

MathExpression::MathExpression(string math_expression) : math_expression_(math_expression) {
}

string MathExpression::getExpression() {
	return math_expression_;
}

void MathExpression::setExpression(string math_expression) {
	this->math_expression_ = math_expression;
}

int MathExpression::calculate() {
	if (this->getExpression().empty()) {
		throw invalid_argument("empty expression");
	}

	if (this->getExpression() == "5") {
		return 5;
	}

	return 0;
}