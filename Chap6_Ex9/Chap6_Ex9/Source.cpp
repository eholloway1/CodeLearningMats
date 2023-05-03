//Evan Holloway 2022
//Program that read digits and makes them integers, i.e. read in '123'
//output "123 is 1 hundred and 2 tens and 3 ones".
//the number is output as an int, handle numbers with up to four digits.
// to get integer value 5 from '5', subtract '5' from '0'

//---------------------------------------------------------

#include "../../std_lib_facilities.h"

//---------------------------------------------------------

constexpr int INTEGER_CAP = 4; //1.0 handles integers up to 4 digits.

//---------------------------------------------------------

void exercise9(); //base function for project
vector<char> getInput(); //prompt user for their input
int getSum(vector<char>); //calculate and return sum of input
void printOutput(vector<char>, int); //print the proper output

//---------------------------------------------------------

int main()
try {
	exercise9();
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops, unkown exception\n";
	keep_window_open();
	return 2;
}

//---------------------------------------------------------

void exercise9() //base function for project
{
	vector<char> in = getInput();
	int total = getSum(in);
	printOutput(in, total);
}

//---------------------------------------------------------

vector<char> getInput() //prompt user for their input
{
	cout << "Please enter the int you would like evaluated (input ended via entering 4 digits or ending with '!')\n";
	vector<char> temp;
	char input;
	for (int i = 0; i < INTEGER_CAP; ++i)
	{
		cin >> input;
		if (input == '!')
			break;
		else if (input > '0' && input <= '9')
			temp.push_back(input);
		else
			error("Please input a valid character digit");
	}
	//for (int i = 0; i < temp.size(); i++)
	//{
	//	cout << temp[i] << '\t';
	//}
	//cout << '\n';

	return temp;
}

//---------------------------------------------------------

int getSum(vector<char> inny) //calculate and return sum of input
{
	int mult = 0, sum = 0, current = 0;
	for (int i = inny.size(), j = 0; i > 0; --i)
	{
		current = inny[j] - '0';
		if(i == INTEGER_CAP)
		{
			mult = 1000;
			current *= mult;
			sum += current;
			//cout << sum << "sum\t";
		}
		else if(i == INTEGER_CAP - 1)
		{
			mult = 100;
			current *= mult;
			sum += current;
			//cout << sum << "sum\t";
		}
		else if(i == INTEGER_CAP - 2)
		{
			mult = 10;
			current *= mult;
			sum += current;
			//cout << sum << "sum\t";
		}
		else if(i == INTEGER_CAP - 3)
		{
			mult = 1;
			current *= mult;
			sum += current;
			//cout << sum << "sum\t";
		}
		j++;
		//cout << mult << "mult\t";
	}
	//cout << '\n';
	return sum;
}

//---------------------------------------------------------

void printOutput(vector<char> inny, int sum) //print the proper output
{
	cout << sum << " is ";
	for (int i = inny.size(), j = 0; i > 0; --i, ++j)
	{
		if (i == 4)
		{
			if(inny[j] == '1')
				cout << inny[j] << " thousand";
			else
				cout << inny[j] << " thousands";
		}
		else if (i == 3)
		{
			if (inny[j] == '1')
				cout << inny[j] << " hundred";
			else
				cout << inny[j] << " hundreds";
		}
		else if (i == 2)
		{
			if (inny[j] == '1')
				cout << inny[j] << " ten";
			else
				cout << inny[j] << " tens";
		}
		else if (i == 1)
		{
			if (inny[j] == '1')
				cout << inny[j] << " one";
			else
				cout << inny[j] << " ones";
			break;
		}
		cout << " and ";
	}
	cout << ".\n";
}

//---------------------------------------------------------

