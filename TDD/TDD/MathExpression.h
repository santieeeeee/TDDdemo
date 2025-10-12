#include <string>
#include <stdexcept>

using namespace std;

class MathExpression {
private:
	string math_expression_;
public:
	MathExpression(string math_expression);
	string getExpression();
	void setExpression(string math_expression);
	int calculate();
};