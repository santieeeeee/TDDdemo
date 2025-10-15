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
        throw std::invalid_argument("empty expression");
    }

    size_t i = 0;
    int result = 0;
    bool negative = false;

    if (expr[i] == '+' || expr[i] == '-') {
        negative = (expr[i] == '-');
        i++;
    }

    size_t start = i;
    while (i < expr.size() && isdigit(expr[i])) {
        i++;
    }
    result = stoi(expr.substr(start, i - start));
    if (negative) {
        result *= -1;
    }

    while (i < expr.size()) {
        char op = expr[i++];
        start = i;
        while (i < expr.size() && isdigit(expr[i])) {
            i++;
        }

        int num = stoi(expr.substr(start, i - start));

        switch (op) {
        case '+': result += num; break;
        case '-': result -= num; break;
        case '*': result *= num; break;
        case '/':
            if (num == 0) throw std::invalid_argument("division by zero");
            result /= num;
            break;
        default:
            throw std::invalid_argument("unsupported operator");
        }
    }

    return result;
}