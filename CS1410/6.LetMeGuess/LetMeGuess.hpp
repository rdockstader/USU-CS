#ifndef LET_ME_GUESS_HPP
#define LET_ME_GUESS_HPP

#include <memory>
#include <string>
#include <iostream>

enum Nodetype
{
		AnswerType
	,	QuestionType
};

struct Node
{
	Node(std::string data, Nodetype type) : data(data), type(type), Yes(nullptr), No(nullptr) {}
	std::string data;
	std::shared_ptr<Node> Yes;
	std::shared_ptr<Node> No;
	Nodetype type;
};


class LetMeGuess
{
public:
	void gameIntro();
	bool isGameOver();
	std::shared_ptr<Node> getRoot();
	void display();
	void getAnswer();
	void moveNode();
	void makeQuestionAndAnswer();
	void setPlayAgain();
	bool getPlayAgain();
	void makeFirstNode();
	void resetGame();
private:
	std::shared_ptr<Node> root;
	std::shared_ptr<Node> curNode = root;
	std::shared_ptr<Node> previousNode = nullptr;
	bool gameOver = false;
	bool playAgain = true;
	std::string curAnswer;
	void makeNewNodes(std::string, std::string);
	void insertYes(std::string const & value, std::shared_ptr<Node> location, Nodetype type);
	void insertNo(std::string const & value, std::shared_ptr<Node> location, Nodetype type);
	void insertNewYes(std::string const & value, std::shared_ptr<Node> location, Nodetype type);
	void makeNewRoot(std::string const & question, std::string const & answer);
};




#endif
