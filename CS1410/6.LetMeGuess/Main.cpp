#include "LetMeGuess.hpp"


int main()
{
	LetMeGuess game;

	game.gameIntro();
	game.makeFirstNode();
	while (game.getPlayAgain())
	{
		while (!game.isGameOver())
		{
			game.display();
			game.getAnswer();
			game.moveNode();
		}
		game.makeQuestionAndAnswer();
		game.resetGame();
		game.setPlayAgain();
	}
	std::cout << "You have chosen to end the game." << std::endl;
	std::cout << "press any key, then enter to exit console." << std::endl;
	char dummy;
	std::cin >> dummy;

}
