/*
implementation of basic calculator using C++
OOP features
1 digit, basic arithmetic calcuations(+, -, *, /).

by Dongmin Kim(dongmin.kim.0220@gmail.com)
*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

using namespace std;

class Calculator{

private:
	string formula;	

public:

	Calculator() {
		cout << "Calculater Ver1!" << endl;
		
		while(1)
		{
			Calculator::formula = ""; // initialize
			cout << "Input your formula to evalute. Type 'exit' to terminate" << endl;
			getline(cin, Calculator::formula); 

			if(Calculator::formula == "EXIT" ||
				 Calculator::formula == "exit" ||
				 Calculator::formula == "Exit"
			) break;
			
			evaluate();
		}
		
		cout << "Program Ended" << endl;		
	}
 		
	double evaluate()
	{
		string formula_postfix = Calculator::parseString(Calculator::formula);
		double result = evaluatePostfix(formula_postfix);
		cout << "Result: " << result << endl;
		return result;
	}

	int opPriority(char c)
	{
		switch(c)
		{
			case '+': case '-':
				return 1;
			case '*': case '/':
				return 2;
		}
		return 0;
	}
	
	
	double calculate(double a, double b, char op)
	{
		switch(op)
		{
			case '+':
				return a + b;
			case '-':
				return a - b;
			case '*':
				return a * b;
			case '/':
				return a / b;
		}
	}

	string parseString(string s)
	{
		/*
			String Parser
			classify cases by char
			0) blank : pass
			1) digit : just print out (to new string)
			2) op/ parenthesis : get priority.
				2-1) parenthesis '(' - just push, ')' - pop until '(' appears. 
				2-2) stack is empty or current op priority is bigger stack.top
				2-3) current op priority is smaller than stack.top
		*/
	
		string parsedString;
		stack<char> opStack; 


		for (string::iterator c = s.begin(); c != s.end(); ++c)
		{
			// pass the blank
			if(*c == ' ') continue;

			if(isdigit(*c)) // case 1
			{
				parsedString.push_back(*c);
			} 
			else // case 2
			{
				if(*c == '(')
				{
					opStack.push(*c);
				}
				else if(*c == ')')
				{
					while(opStack.top() != '(')
						{
							parsedString.push_back(opStack.top());
							opStack.pop();	
						}
						opStack.pop(); // pop '('
				}
				else if (opStack.empty() || 
						opPriority(opStack.top()) <= opPriority(*c) ) // case 2-1
				{
					opStack.push(*c);
				}
				else // case 2-2
				{
					parsedString.push_back(opStack.top());
					opStack.pop();	
					opStack.push(*c);
				}
	
			}
			
		}

		while(!opStack.empty())
		{
			parsedString.push_back(opStack.top());
			opStack.pop();
		}

		return parsedString;
	}

	double evaluatePostfix(string s)
	{
		stack<double> op;
		double result;
		for (string::iterator c = s.begin(); c != s.end(); ++c)
		{
			if(isdigit(*c))
			{
				char value = *c;
				op.push(atof(&value));
			} 
			else 
			{
				double operand2 = (double)op.top();
				op.pop();
				double operand1 = (double)op.top();
				op.pop();
				double sub_result = calculate(operand1, operand2, *c);
				op.push(sub_result);
			}
		}
	
		result = op.top();
		op.pop(); // empty stack
		return result;
	}

};

int main(void)
{
	Calculator c = Calculator();
	
}
