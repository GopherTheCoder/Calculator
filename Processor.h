#pragma once

#include <stack>

class Processor
{
public:
	Processor();
	~Processor();

	bool Calculate(CString, double&);

private:
	char table[5][5] = {
		{'>','<','<','>','>'},
		{'>','>','<','>','>'},
		{'<','<','<','=',' '},
		{'>','>',' ','>','>'},
		{'<','<','<',' ','='},
	};
	std::stack<double> num;
	std::stack<char> op;

	char opCompare(char, char);
	double getResult(double, char, double);
	void clean();
};

inline Processor::Processor()
{
}

inline Processor::~Processor()
{
}