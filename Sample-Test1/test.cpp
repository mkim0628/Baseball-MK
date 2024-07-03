#include "pch.h"
#include "../Baseball_TDD/baseball.cpp"
using namespace std;

TEST(BaseballTest, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}