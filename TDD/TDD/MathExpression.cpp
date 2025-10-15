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

    int lastTerm = result;

    while (i < expr.size()) {
        char op = expr[i++];
        start = i;
        while (i < expr.size() && isdigit(expr[i])) {
            i++;
        }

        int num = stoi(expr.substr(start, i - start));

        if (op == '+' || op == '-') {
            int signedNum = (op == '+') ? num : -num;
            result += signedNum;
            lastTerm = signedNum;
        }
        else if (op == '*' || op == '/') {
            int newLast;
            if (op == '*') {
                newLast = lastTerm * num;
            }
            else {
                if (num == 0) throw std::invalid_argument("division by zero");
                newLast = lastTerm / num;
            }

            result = result - lastTerm + newLast;
            lastTerm = newLast;
        }
    }
    return result;
}