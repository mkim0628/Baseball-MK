#include "pch.h"
#include "../Baseball_TDD/baseball.cpp"
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
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

TEST_F(BaseballFixture, passCase) {
	GuessResult result = game.guess("123");
	
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}
