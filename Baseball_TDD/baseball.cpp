//#include <stdexcept>
#include <iostream>
using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		throw length_error("Must be three letters.");
	}
};