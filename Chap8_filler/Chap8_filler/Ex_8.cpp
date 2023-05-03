#include "../../std_lib_facilities.h"
/*
	Evan Holloway
	May 2023

	Ex_8, but with inf number of names && ages

*/

void printer(vector<string>, vector<double>);
void getter(vector<string>&, vector<double>&);
void sorter(vector<string>&, vector<double>&);

int main()
try {

	vector<string> name;
	vector<double> age;

	getter(name, age);
	printer(name, age);
	sorter(name, age);
	printer(name, age);

	keep_window_open();
	return 0;
}
catch (exception& e) {

	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {

	cerr << "Uknown exception\n";
	keep_window_open();
	return 2;
}

void printer(vector<string> inName, vector<double> inAge) {

	for (int i = 0; i < inName.size(); i++)
	{
		cout << "name: " << inName[i] << " age: " << inAge[i];

		if (i == inName.size() - 1) cout << '\n';
		else cout << ", ";
	}

}

void getter(vector<string>& outName, vector<double>& outAge) {

	string in = "";
	double ages = 0.0;

	cout << "Please enter some names (stop input with '|'):\n";

	for(;;){
		cin >> in;
		if(in == "|") break;
		outName.push_back(in);
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	cin >> in;
	//	outName.push_back(in);
	//}

	cout << "Please enter the ages of the " << outName.size() << " people, in order(end input with 9999) :\n";

	for(;;){
		cin >> ages;
		if(ages == 9999) break;
		outAge.push_back(ages);
	} 

	//for (int i = 0; i < 5; i++)
	//{
	//	cin >> ages;
	//	outAge.push_back(ages);
	//}

	if(outName.size() != outAge.size()) error("You must enter the same number of ages as names");
}

void sorter(vector<string>& inName, vector<double>& inAge) {

	vector<string> tempName = inName;
	vector<double> tempAge = inAge;

	sort(inName.begin(), inName.end());

	for (int i = 0; i < inName.size(); i++) {
		for (int j = 0; j != inName.size(); j++) {
			if (inName[i] == tempName[j]) {
				tempAge[i] = inAge[j];
			}
		}
	}

	inAge = tempAge;

}
