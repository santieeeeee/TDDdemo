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

    size_t opPos = string::npos;
    for (size_t i = 1; i < expr.size(); ++i) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') { 
            opPos = i;
            break;
        }
    }

    if (opPos == string::npos) {
        return std::stoi(expr);
    }

    if (opPos == 0) {
        return std::stoi(expr);
    }

    string left = expr.substr(0, opPos);
    char op = expr[opPos];
    string right = expr.substr(opPos + 1);

    int L = std::stoi(left);
    int R = std::stoi(right);

    switch (op) {
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