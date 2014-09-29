// Post-Fix Expression
// Austin Andrews
// Visual Studio 2013
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

const string IN = "postfix.in";
const string OUT = "postfix.out";

stack<float> Stack;

string define(string readline, char& key)
{
	string op;

	key = readline[1];
	int start = readline.find("\"");
	int end = readline.find_last_of("\"");

	op = readline.substr(start, end);

	//cout << "define() : " << op << endl;

	return op;
}

void duplicate(string& op)
{

}

void swap(string& op)
{

}

float convertToNumber(char x)
{
	float result = x - 48.0;

	cout << "char : " << x << " result : " << result << endl;

	return result;
}

float evaluate(string readline, string op , char key)
{
	float result;
	float convertedNumber;
	float temp;
	readline = readline.substr(1, readline.length());
	// D+" 0%--"
	for (unsigned int i = 0; i < readline.length(); i++)
	{
		if (readline[i] != ' ' && readline[i] != '\"')
		{
			if (readline[i] >= 48 && readline[i] <= 57)
			{
				convertedNumber = convertToNumber(op[i]);
				Stack.push(convertedNumber);
			}
			else if (readline[i] == key)
			{
				for (unsigned int j = 0; j < op.length(); j++)
				{
					if (op[j] != ' ' && op[j] != '\"')
					{
						if (op[j] >= 48 && op[j] <= 57)
						{
							convertedNumber = convertToNumber(op[j]);
							Stack.push(convertedNumber);
						}
						else
						{
							// if not a number, pop
							temp = Stack.top();

							if (op[i] == '+')
								Stack.push(Stack.top() + temp);
							else if (op[i] == '-')
								Stack.push(Stack.top() - temp);
							else if (op[i] == '*')
								Stack.push(Stack.top() * temp);
							else if (op[i] == '/')
								Stack.push(Stack.top() / temp);
						}
					}
				}
			}
			else
			{
				temp = Stack.top();

				if (readline[i] == '+')
					Stack.push(Stack.top() + temp);
				else if (readline[i] == '-')
					Stack.push(Stack.top() - temp);
				else if (readline[i] == '*')
					Stack.push(Stack.top() * temp);
				else if (readline[i] == '/')
					Stack.push(Stack.top() / temp);

			}
		}
	}

	result = Stack.top();

	cout << "evaluate() : " << result << endl;

	return result;
}

void main()
{
	ifstream fin(IN);
	if (fin)
	{
		ofstream fout(OUT);
		string readline;
		string op;
		float result;
		char key;

		getline(fin, readline);
		while (readline != "Q")
		{
			if (readline[0] == 'D')
				op = define(readline, key);
			else if (readline[0] == 'E')
				if (op != "")
					result = evaluate(readline, op, key);



			getline(fin, readline);
		}


		fout.close();
		fin.close();
	}
	else
	{
		cout << "Input file not found." << endl;
	}
}