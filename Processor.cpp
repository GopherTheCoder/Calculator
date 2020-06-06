#include "pch.h"
#include "Processor.h"
#include <afx.h>
#include <stack>

bool Processor::Calculate(CString formula, double& res) {
	clean();
	formula.AppendChar('#');
	op.push('#');

	bool newNum = true, dot = false;
	int count = 0, length = formula.GetLength();
	while (count != length || !op.empty()) {
		if (formula[count] == '.') {
			if (dot) return false;
			dot = true;
			count++;
		}
		else if (formula[count] <= '9' && formula[count] >= '0')
		{
			if (dot) {
				if (num.empty()) return false;
				double t = num.top() + (formula[count] - 48) * 0.1;
				num.pop();
				num.push(t);
			}
			else if (newNum) {
				num.push(formula[count] - 48);
				newNum = false;
			}
			else {
				if (num.empty()) return false;
				double t = num.top() * 10 + formula[count] - 48;
				num.pop();
				num.push(t);
			}
			count++;
		}
		else {
			dot = false;
			newNum = true;
			if (op.empty()) return false;
			switch (opCompare(op.top(), formula[count]))
			{
			case '<':
				op.push(formula[count]);
				count++;
				break;

			case '=':
				op.pop();
				count++;
				break;

			case '>': {
				if (op.empty()) return false;
				char o = op.top();
				op.pop();
				if (num.empty()) return false;
				double b = num.top();
				num.pop();
				if (num.empty()) return false;
				double a = num.top();
				num.pop();

				num.push(getResult(a, o, b)); }
					break;

			case ' ':
				return false;

			default:
				break;
			}
		}
	}

	if (num.empty()) return false;
	res = num.top();
	num.pop();
	return true;
}

char Processor::opCompare(char a, char b)
{
	switch (a)
	{
	case '+':
	case '-':
		a = 0; break;
	case '*':
	case '/':
		a = 1; break;
	case '(':
		a = 2; break;
	case ')':
		a = 3; break;
	case '#':
		a = 4; break;

	default:
		return NULL;
	}

	switch (b)
	{
	case '+':
	case '-':
		b = 0; break;
	case '*':
	case '/':
		b = 1; break;
	case '(':
		b = 2; break;
	case ')':
		b = 3; break;
	case '#':
		b = 4; break;

	default:
		return NULL;
	}

	return table[a][b];
}

double Processor::getResult(double a, char op, double b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		break;
	}

	return 0;
}

void Processor::clean()
{
	while (!num.empty())
		num.pop();
	while (!op.empty())
		op.pop();
}
