#ifndef TICTAC_DISPLAY
#define TICTAC_DISPLAY


enum class TicTac
{
	PLAYER_X_TURN,
	PLAYER_O_TURN,
	NO_WINNER_YET,
	PLAYER_X_WIN,
	PLAYER_O_WIN,
	DRAW

};

class TicTacToe
{
public:
	TicTacToe();
	TicTac displayBoard(TicTac PlayerTurn, int PlayerChoice);
	TicTac takeTurn(TicTac PlayerTurn);
	void endGame(void);
	void winnaWinnaChickenDinna(TicTac AnyWinnerYet);
	bool playAgainFunction(void);
	TicTac beginGame(void);
	int roll(void);
	TicTac returnWinner(TicTac whosTurn);
private:
	char space1, space2, space3, space4, space5, space6, space7, space8, space9, thisTurnPlayer;
};
#endif
