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
		int k = 1;
		auto it = find(expr.begin(), expr.end(), '+');
		if (it == expr.end()) {
			it = find(expr.begin(), expr.end(), '-');
			if (it == expr.end()) {
				return stoi(expr);
			}
			else {
				k = -1;
			}
		}
		string number(expr.begin(), it);
		if (number.empty()) {
			return stoi(expr);
		}
		expr.erase(expr.begin(), it + 1);
		int answer = stoi(number) + k * stoi(expr);

		return answer;
}