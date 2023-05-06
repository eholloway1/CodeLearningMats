#include "../../std_lib_facilities.h"
/*

	Evan Holloway
	May 2023

	write funciton that finds the smallest and largest elements, mean, and median of a vector argument
	Either return a struct contating the results or pass them back through reference arguments.

*/

struct excercise {
	private:
		double large;
		double small;
		double mean;
		double median;

	public:
		excercise()
			:large{0.0}, small{0.0}, mean{0.0}, median{0.0}
			{}
		excercise(double l, double s, double mea, double med)
			:large{l}, small{s}, mean{mea}, median{med}
			{}
		~excercise() {}

		void Calculate(const vector<double>& in);
		void printVars();
};
int main()
try {

	excercise example;

	vector<double> A{4, 3, 4, 3, 2, 2};

	example.Calculate(A);
	example.printVars();

	cout << '\n';

	vector<double> B{4, 1, 7};
	
	example.Calculate(B);
	example.printVars();

	cout << '\n';

	vector<double> C{1, 4, 2, 5, 0};

	example.Calculate(C);
	example.printVars();

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Uknown exception" << endl;
	keep_window_open();
	return 2;
}

void excercise::Calculate(const vector<double>& in) {

	if(in.size() == 0) error("please pass a vector containing elements to Calcuate");
	if (in.size() == 1) {
		this->large = in[0];
		this->small = in[0];
		this->mean = in[0];
		this->median = in[0];
	}

	double temp_L = in[0];
	double temp_S = in[0];

	for (int i = 1; i < in.size(); i++) {

		if(in[i] > temp_L)
			temp_L = in[i];
		if(in[i] < temp_S)
			temp_S = in[i];
	}

	this->large = temp_L;
	this->small = temp_S;

	double total = 0.0;

	for (int i = 0; i < in.size(); i++) {

		total += in[i];
	}

	total /= in.size();
	this->mean = total;

	vector<double> temp = in;

	sort(temp.begin(), temp.end());

	if (temp.size() % 2 == 0)
	{
		double temp_1 = temp[(temp.size() / 2) - 1];
		double temp_2 = temp[(temp.size() / 2) + 1];
		total = temp_1;
		total += temp_2;
		total /= 2;
		this->median = total;
	}

	else
		this->median = temp[temp.size() / 2];

}

void excercise::printVars() {
	
	cout << "largest val: " << this->large << '\n'
		<< "smallest val: " << this->small << '\n'
		<< "mean val: " << this->mean << '\n'
		<< "median val: " << this-> median << '\n';
	
}