//Evan Holloway 2022
//game "bulls and cows"
//program generates a vector of four random characters
//user inputs guesses of four characters
//if input letter is right letter in right spot +1 bull
//if input letter is right letter in wrong spot +1 cow

//-------------------------------------------------

#include "../../std_lib_facilities.h"

//-------------------------------------------------

const vector<char> acceptedInput = {'a', 'b' , 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
vector<char> Solution = { 'a', 'e', 'f', 'j' };
int cow = 0, bull = 0;

//-------------------------------------------------

vector<char> getInput();
void checkAnswer(vector<char>);
void checkInput(char);

//-------------------------------------------------

int main()
try {
	cout << "Please enter your guesses for what the four random characters may be:\n";
	cout << "Note: seperate your entry with spaces, ',' not accepted.\n";
	for (; bull != 4;) { //while the user has not gotten 4 bulls
		vector<char> Input = getInput();
		checkAnswer(Input);
	}
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops, unkown exception!";
	keep_window_open();
	return 2;
}

//-------------------------------------------------

vector<char> getInput() { //ask user to enter their guess of the four characters
	vector<char> in;
	int index = 0;
	char entry;

	while (index < 4) {
		if (cin) {
			cin >> entry;
			checkInput(entry);
			in.push_back(entry);
			index++;
		}
		else {
			error("Please enter a valid input");
		}
	}
	return in;
}

//-------------------------------------------------

void checkAnswer(vector<char> in) { //check the input against the program-generated solution
	for (int i = 0; i < in.size(); i++) { //for every character in the 'in' vector...
		for (int j = 0; j < Solution.size(); j++) { //go over every character in the solution vector
			if (in[i] == Solution[j]) {
				if (i == j)
					bull++;
				else
					cow++;
			}
		}
	}
	cout << "Bulls: " << bull << " Cows: " << cow << '\n';
	if (bull == 4)
		cout << "Congrats, you win!\n";
	else {
		cout << "Oof, try again.\n";
		bull = 0;
		cow = 0;
	}
}

//-------------------------------------------------

void checkInput(char in) {
	for (int i = 0; i < acceptedInput.size(); i++) {
		if(in == acceptedInput[i])
			break;
		error("Please enter valid character input");
	}
}
