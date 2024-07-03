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

TEST_F(BaseballFixture, threeStrikes) {
	GuessResult result = game.guess("123");
	
	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, twoStrikesZeroBall) {
	GuessResult result = game.guess("129");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);

	result = game.guess("923");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
	
	result = game.guess("153");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}