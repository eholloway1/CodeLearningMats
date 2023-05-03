
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

	Revision history:
		Originally written by Bjarne Stroustrup
		Revised by Evan Holloway Jan 2023
		Revised by Evan Holloway Jan 2023
		Revised by Evan Holloway Feb 2023
		Revised by Evan Holloway Apr 2023
		Revised by Evan Holloway Apr 2023
		Revised by Evan Holloway Apr 2023
		This program implements a basic expression calculator.
		Input from cin, output to cout

	Grammar:
		Calculation:
			Statement
			Print
			Quit
			Calculation Statement
		Statement:
			Declaration
			Square root
			Pow
			Expression
		Declaration:
			"let" Name "=" Expression
		Square root:
			"sqrt(" expression ")"
		Pow:
			"pow(" expression "," expression ")"
		Print:
			;
		Quit:
			q
		Expression:
			Term
			Expression + Term
			Expression - Term
		Term:
			Primary
			Term * Primary
			Term / Primary
			Term % Primary
		Primary:
			Number
			( Expression )
			-Primary
			+Primary
		Number:
			floating-point literal

		Input comes from cin through the Token_stream called ts
*/

#include "../../std_lib_facilities.h"

struct Token {
	char kind;
	int value;
	string name;
	Token() :kind(0) {} // default constructor
	Token(char ch) :kind(ch), value(0) { } // initialize with ch
	Token(char ch, int val) :kind(ch), value(val) { } // initialize with kind and value
	Token(char ch, string n) :kind(ch), name(n) { } // initialize with kind and name
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L'; // declaration token
const char sqrrt = 'S'; // square token
const char power = 'P'; // power token
const char quit = 'Q'; // quit token
const char print = ';'; // print token
const char number = '8'; // number token
const char name = 'a'; // name token
const string declkey = "#"; // declaration keyword
const char declkeyCh = '#'; // delcaration keywork, char
const string sqrtKey = "sqrt"; // square root keyword
const string quitKey = "quit"; // quit keyword
const string powKey = "pow"; // power keyword
const char underExcept = '_'; // allow '_' in variable names
const char assign = '=';
const string assignKey = "=";
const string constKey = "const";
const char constant = 'c';
//const string spaceKey = " ";
const char help = 'H';
const string helpKey = "help";
const char sqr = 'e';
const string sqrKey = "sqr";

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin.get(ch);
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:
	case power:
	case ',':
	{
		//Token tmp = Token(ch);
		//full = true;
		//buffer = tmp;
		//return tmp;
		return Token(ch);
	}
	//case '\n':
	//{
	//	return Token(print);
	//}
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	
		cin.putback(ch);
		double val, fratVal, intVal;
		cin >> val;
		int val2 = narrow_cast<int>(val);
		fratVal = modf(val, &intVal);
		if(fratVal > 0) error("overflow error, please enter only ints");
		//Token tmp = Token(number, val);
		//full = true;
		//buffer = tmp;
		//return tmp;
		return Token(number, val2);
	}
	default:
		//cin.putback(ch);
		// 
		if (isspace(ch))
		{
			return Token(print);
		}
		if (isalpha(ch) || ch == declkeyCh || ch == assign) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == declkeyCh || ch == assign) || (ch == underExcept && s.size() > 0)) s += ch;
			//cin.putback(ch);
			if (s == declkey)
			{
				//Token tmp = Token(let, s);
				//full = true;
				//buffer = tmp;
				//return tmp;
				return Token(let, s);
			}
			else if(s == sqrtKey)
			{
				//Token tmp = Token(sqr, s);
				//full = true;
				//buffer = tmp;
				//return tmp;
				cin.putback(ch);
				return Token(sqrrt, s);
			}
			else if(s == powKey)
			{	
				//Token tmp = Token(power, s);
				//full = true;
				//buffer = tmp;
				//return tmp;
				cin.putback(ch);
				return Token(power, s);
			}
			else if(s == quitKey)
			{	
				//Token tmp = Token(quit, s);
				//full = true;
				//buffer = tmp;
				//return tmp;
				cin.putback(ch);
				return Token(quit, s);
			}
			else if(s == assignKey)
			{	
				//Token tmp = Token(assign, s);
				//full = true;
				//buffer = tmp;
				//return tmp;
				return Token(assign, s);
			}
			else if (s == constKey)
			{
				return Token(constant, s);
			}
			else if (s == helpKey)
			{
				return Token(help, s);
			}
			else if (s == sqrKey)
			{
				cin.putback(ch);
				return Token(sqr, s);
			}
			//else if (s == spaceKey)
			//{
			//	return Token(print);
			//}
			else
			{
				//Token tmp = Token(name, s);
				//full = true;
				//buffer = tmp;
				//return tmp;
				return Token(name, s);
			}
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
// ignore input up to c
{
	if (full && c == buffer.kind) {
		full = false;
		buffer = 0;
		return;
	}
	else
		cin.putback(c);

	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	int value;
	bool constant;
	Variable(string n, int v) :name(n), value(v), constant(false) { }
	Variable(string n, int v, bool c) :name(n), value(v), constant(c) {}

};

class Symbol_table {
	vector<Variable> names;
	
public:
	int get_value(string s);
	void set_value(string s, int d);
	bool is_declared(string s);
	int define_name(string var, int val, bool c);
};

Symbol_table st;

int Symbol_table::get_value(string s)
// get value of Variable object s
{
	for (Variable& v : names)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void Symbol_table::set_value(string s, int d)
// set value of variable object s to d
{
	for (Variable& v : names)
		if (v.name == s) {
			if(v.constant == true) error("Cannot change the value of a constant variable");
			else
			{
				v.value = d;
				return;
			}
		}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
// is Variable object s already declared
{
	for (Variable& v : names)
		if (v.name == s) return true;
	return false;
}

int Symbol_table::define_name(string var, int val, bool c)
// define a new Variable object
{
	if(is_declared(var)) error(var, " declared twice");
	names.push_back(Variable{var, val, c});
	return val;
}

Token_stream ts;

int expression();

int primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	
		int d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return st.get_value(t.name);
	case power:
		ts.unget(t);
	case sqr:
		ts.unget(t);
	case assign:
		ts.unget(t);
	default:
		error("primary expected");
	}
}

int term()
{
	int left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	int d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

int expression()
{
	int left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

int statement();

int declaration()
{
	Token t = ts.get();
	int d = 0.0;
	if (t.kind == constant)
	{
		Token t2 = ts.get();
		if (t2.kind != name) error("name expected in declaration");
		Token t3 = ts.get();
		if (t3.kind != assign) error("= missing in declaration of ", t.name);
		d = statement();
		st.define_name(t2.name, d, true);
	}
	else
	{
		if (t.kind != name) error("name expected in declaration");
		Token t2 = ts.get();
		if (t2.kind != assign) error("= missing in declaration of ", t.name);
		d = statement();
		st.define_name(t.name, d, false);
	}

	return d;
}

int squareRoot()
{
	Token t = ts.get();
	if(t.kind != '(') error("( expected for square");
	int d = expression();
	if(d < 0) error("cannot take the sqaure root of a negative");
	d = sqrt(d);
	Token t2 = ts.get();
	if(t2.kind != ')') error(") missing in end of sqrt");
	return d;
}
int pow()
{
	Token t = ts.get();
	if(t.kind != '(') error("( expected for pow");
	int left = expression();
	Token t2 = ts.get();
	if(t2.kind != ',') error(", expected in pow");
	int right = narrow_cast<int>(expression());
	Token t3 = ts.get();
	if(t3.kind != ')') error(") mssing in end of pow");
	int sum = left;
	for (int i = 1; i < right; i++)
	{
		sum *= left;
	}
	return sum;
	
}
int Sqaure()
{
	Token t = ts.get();
	if(t.kind != '(') error("'(' expected for sqr");
	int val = expression();
	val *= val;
	Token t2 = ts.get();
	if(t2.kind != ')') error("')' expected for sqr");
	return val;
}
void helper()
{
	cout << "Weclome to the Calculator 0.1\n";
	cout << "The currently funcitoning operations are:\n";
	cout << "+, -, *, /, %\n";
	cout << "pow(x, y),  sqrt(x)\n";
	cout << "you can declare variables using " << declkey << " var_name " << assign << " value " << print << '\n';
	cout << "TIP: add a 'space' between all inputs. e.g. '# d = 5 ;'\n";
}
int assignment()
{
	//Token t = ts.get();
	//if(is_declared(t.name) != true) error("assigning undeclared variable");
	Token t2 = ts.get();
	//cout << t2.name << '\t' << t2.value << '\n';
	if(st.is_declared(t2.name) != true) error("assigning undeclared variable");
	Token t3 = ts.get();
	st.set_value(t2.name, t3.value);
	return t3.value;
}

int statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case sqr:
		return Sqaure();
	case power:
		return pow();
	case sqrrt:
		return squareRoot();
	case help:
	{
		helper();
		return 0;
	}
	case name:
	{
		Token t2 = ts.get();

		if (t2.kind == assign)
		{
			ts.unget(t2);
			ts.unget(t);
			return assignment();
		}
		else/* if (t2.kind == print)*/
		{
			ts.unget(t2);
			ts.unget(t);
			return expression();
		}
		//error("'=' expected in variable assignment");
	}
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	st.define_name("k", 1000, true);
	calculate();
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open("~~");
	return 2;
}