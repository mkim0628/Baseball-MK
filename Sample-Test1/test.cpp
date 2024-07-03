#include "pch.h"
#include "../Baseball_TDD/baseball.cpp"
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assetIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assetIllegalArgument("12");
	assetIllegalArgument("12s");
	assetIllegalArgument("121");
}