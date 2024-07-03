//#include <stdexcept>
#include <iostream>
using namespace std;
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question) : question{ question } {};
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		int strikes = 0, balls = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) strikes++;
		}
		return { false, strikes, balls };
	}

private:
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[0] == guessNumber[2];
	}

	string question;
};