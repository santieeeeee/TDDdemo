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

		auto it = find(expr.begin(), expr.end(), '+');
		if (it == expr.end()) {
			return stoi(expr);
		}
		string number(expr.begin(), it);
		expr.erase(expr.begin(), it + 1);
		int answer = stoi(number) + stoi(expr);

		return answer;
}