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

    size_t pos = string::npos;
    for (size_t i = 1; i < expr.size(); ++i) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') { 
            pos = i;
            break;
        }
    }

    if (pos == string::npos) {
        return std::stoi(expr);
    }

    if (pos == 0) {
        return std::stoi(expr);
    }

    string left = expr.substr(0, pos);
    char Operator = expr[pos];
    string right = expr.substr(pos + 1);

    int L = std::stoi(left);
    int R = std::stoi(right);

    switch (Operator) {
    case '+': return L + R;
    case '-': return L - R;
    case '*': return L * R;
    case '/':
        if (R == 0) throw std::invalid_argument("division by zero");
        return L / R;
    default:
        throw std::invalid_argument("unsupported operator");
    }
}