#include<iostream>
#include<string>

class Expression {
public:
	virtual void evaluate() const = 0;
};

class NumberExpression : public Expression {
public:
	NumberExpression(int num) : number(num) {}

	int evaluate() const override {
		return number;
	}

private:
	int number;
};

class AdditionExpression : public Expression{
public:
	AdditionExpression(Expression* lhs, Expression* rhs) : left(lhs) : right(rhs) {}

	int evaluate() const override {
		return left->evaluate() + right->evaluate();
	}

private:
	Expression* left;
	Expression* right;
};

class Parser {
public:
	Expression* parse(const std::string& input){
		int firstNumber = 10;
		int secondNumber = 14;
		Expression* left = new NumberExpression(firstNumber);
		Expression* right = new NumberExpression(secondNumber);
		return new AdditionExpression(left, right);
	}
};

int int main(int argc, char const *argv[])
{
	Parser parser; 

	std::string expression1 = "10 + 5";
	Expression* ast1 = parser.parse(expression1);

	int result1 = ast1 -> evaluate();
	std::cout << expression1 << " = " << result1 << std::endl;

	std::string expression2 = "7 + 3";
	Expression* ast2 = parser.parse(expression2);

	int result2 = ast2 -> evaluate();
	std::cout << expression2 << " = " << result2 << std::endl;

	delete ast1;
	delete ast2;

	return 0;
}