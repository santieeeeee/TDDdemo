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

	string expr = this->getExpression();
	if (expr.empty()) {
		throw invalid_argument("empty expression");
	}

	auto pos = expr.find_first_of("+-", 1);
	if (pos == string::npos) {
		return stoi(expr);
	}

	string left = expr.substr(0, pos);
	char Operator = expr[pos];
	string right = expr.substr(pos + 1);


	if (left.empty() || right.empty()) {
		throw invalid_argument("invalid expression");
	}

	int L = stoi(left);
	int R = stoi(right);
	return (Operator == '+') ? (L + R) : (L - R);	
}