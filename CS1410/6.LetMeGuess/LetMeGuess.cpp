#include "LetMeGuess.hpp"


void LetMeGuess::gameIntro()
{
	std::cout << "Welcome to Let Me Guess!!" << std::endl;
	std::cout << "In this game, the following will happen:" << std::endl;
	std::cout << "NOTE: If there isn't a knowledge base, you're first object ";
	std::cout << "will have to be entered before playing." << std::endl;
	std::cout << "1. You will think of an object (I.E. an elephant)" << std::endl;
	std::cout << "2. The game will then try to guess that object" << std::endl;
	std::cout << "3. Answer the games questions using \"yes\" or \"no\" " << std::endl;
	std::cout << "   NOTE: Answers are case sensitive." << std::endl;
	std::cout << "3. If the game is unable to guess the object you " << std::endl;
	std::cout << "   are thinking of, it will ask you how it could " << std::endl;
	std::cout << "   guessed what you were thinking." << std::endl;
	std::cout << "4. You will then get to come up with a question " << std::endl;
	std::cout << "   that could have led to your answer!" << std::endl;
	std::cout << std::endl;

	//Uncomment the following after knowledgebase is setup.
	//std::cout << "After you end the game, your questions/answers will" << std::endl;;
	//std::cout << "Be saved to our knowledge base!" << std::endl;

	//comment after knowledge base is setup:
	std::cout << "After you end the game, all you answers/questions will be lost :(" << std::endl;

	std::cout << std::endl;

	std::cout << "Let's begin!" << std::endl;
	std::cout << "Please think of an object to compare against..." << std::endl;

}

void LetMeGuess::display()
{
	if (curNode->type == AnswerType)
	{
		std::cout << "Is what your thinking a " << curNode->data << "?" << std::endl;
	}
	else
	{
		std::cout << curNode->data << std::endl;
	}
}

void LetMeGuess::getAnswer()
{
	auto realAnswer = false;

	std::cout << std::endl;
	while (realAnswer == false)
	{
		std::cin >> curAnswer;
		if (curAnswer != "yes" && curAnswer != "no")
		{
			std::cout << "Invalid answer, please type \"yes\" or \"no\". " << std::endl;
			std::cin.clear();
			realAnswer = false;
		}
		else
		{
			realAnswer = true;
		}
	}
}


void LetMeGuess::moveNode()
{
	if (curAnswer == "yes")
	{
		if (curNode->Yes != nullptr)
		{
			previousNode = curNode;
			curNode = curNode->Yes;
			curAnswer.clear();
		}
		else
		{
			gameOver = true;
		}
	}
	else if (curAnswer == "no")
	{
		if (curNode->No != nullptr)
		{
			previousNode = curNode;
			curNode = curNode->No;
			curAnswer.clear();
		}
		else
		{
			gameOver = true;
		}
	}
	else
	{
		std::cout << "answer entered was invalid, and you shouldn't have even gotten here." << std::endl;
	}

}

void LetMeGuess::setPlayAgain()
{
	bool validAnswer = false;
	char answer;
	std::cout << "Would you like to play again?? (y/n)" << std::endl;
	std::cin >> answer;
	std::cout << std::endl;
	while (!validAnswer)
	{
		if (answer == 'y' || answer == 'Y')
		{
			validAnswer = true;
			playAgain = true;
			break;
		}
		if (answer == 'n' || answer == 'N')
		{
			validAnswer = true;
			playAgain = false;
			break;
		}
		else
		{
			validAnswer = false;
			std::cout << answer << " is not a valid answer, please enter \"y\" or \"n\"" << std::endl;
			std::cin.clear();
			std::cin >> answer;
			std::cout << std::endl;
		}
	}
}

void LetMeGuess::makeQuestionAndAnswer()
{
	if (curAnswer == "yes")
	{
		std::cout << "What you were thinking was a " << curNode->data << " !!" << std::endl;
		std::cout << "The game correctly guessed what you were thinking." << std::endl;
		std::cout << ".....GAME OVER....." << std::endl;
		return;
	}
	std::cout << "The game couldn't guess what you were thinking! " << std::endl;;
	std::cout << std::endl;
	std::cin.clear();


	std::string newQuestion, newAnswer, dummy;

	std::cout << "What Answer were you thinking: ";
	std::cin >> newAnswer;
	std::cout << std::endl;
	std::cout << "What could i have have asked to know you're thinking of a(n) " << newAnswer << " and not a(n) " << curNode->data << "?" ;
	std::getline(std::cin, dummy);
	std::getline(std::cin, newQuestion);
	std::cout << std::endl;
	makeNewNodes(newQuestion, newAnswer);
}

void LetMeGuess::makeFirstNode()
{
	if (!root)
	{
		std::string answer;
		std::cout << "Please enter the first answer" << std::endl;
		std::cin >> answer;
		auto node = std::make_shared<Node>(answer, AnswerType);
		root = node;
		curNode = node;
		previousNode = node;
	}
}

void LetMeGuess::makeNewNodes(std::string question, std::string answer)
{
	if (curNode->type == QuestionType)
	{
		insertNo(question, curNode, QuestionType);
		insertYes(answer, curNode->No, AnswerType);
	}
	else if (curNode->type == AnswerType)
	{
		if (curNode == root)
		{
			makeNewRoot(question, answer);
		}
		else
		{
			if (previousNode->Yes == curNode)
			{
				insertYes(question, previousNode, QuestionType);
				insertNewYes(answer, previousNode->Yes, AnswerType);
			}
			else
			{
				insertNo(question, previousNode, QuestionType);
				insertNewYes(answer, previousNode->No, AnswerType);
			}
		}
	}
}


void LetMeGuess::insertYes(std::string const & value, std::shared_ptr<Node> location, Nodetype type)
{
	if (!location) return;
	auto node = std::make_shared<Node>(value, type);
	node->Yes = location->Yes;
	location->Yes = node;
}

void LetMeGuess::insertNo(std::string const & value, std::shared_ptr<Node> location, Nodetype type)
{
	if (!location) return;
	auto node = std::make_shared<Node>(value, type);
	node->No = location->No;
	location->No = node;
}

void LetMeGuess::insertNewYes(std::string const & value, std::shared_ptr<Node> location, Nodetype type)
{
	if (!location) return;
	auto node = std::make_shared<Node>(value, type);
	location->No = location->Yes;
	location->Yes = node;
}

void LetMeGuess::makeNewRoot(std::string const & question, std::string const & answer)
{
	auto qNode = std::make_shared<Node>(question, QuestionType);
	auto aNode = std::make_shared<Node>(answer, AnswerType);
	auto temp = root;

	root = qNode;
	qNode->Yes = aNode;
	qNode->No = temp;

}

void LetMeGuess::resetGame()
{
	gameOver = false;
	curNode = root;
	previousNode = nullptr;
	curAnswer.clear();
}

bool LetMeGuess::isGameOver()
{
	return gameOver;
}

std::shared_ptr<Node> LetMeGuess::getRoot()
{
	return root;
}

bool LetMeGuess::getPlayAgain()
{
	return playAgain;
}

