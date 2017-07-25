#ifndef SCRABBLE_HOUSE_RULES_HPP
#define SCRABBLE_HOUSE_RULES_HPP

//built in
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
//hpp's
#include"HashTable.hpp"


struct usedWord {
	std::string word;
	int uses = 0;

	std::ostream& operator<<(std::ostream& os)
	{
		os << word;
		return os;
	}
};



class scrabbleHouseRules
{
public:
	void playFromFile(std::ifstream& file);
	void resetGame();


private:
	//private variables
	HashTable<int, usedWord> usedWordTable;
	std::vector<int> scores;
	std::vector<int> wordsOfLength;
	int outputFrequency = 4;
	bool beginGameShown = false;
	//private functions
	int getWordLetterValue(std::string word);
	int getLetterValue(char letter);
	int getWordLengthValue(std::string word);
	int getBonusValue(std::string word);
	std::vector<char> parseString(std::string wordtoParse);

	int getWordASCIIValue(std::string word);

	void beginGame();
	void simpleInsert(std::string word);
	int computeTotalScore();
	int computeWordScore(std::string word);

};

#endif // !SCRABBLE_HOUSE_RULES_HPP

