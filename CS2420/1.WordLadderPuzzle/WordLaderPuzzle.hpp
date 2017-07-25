#ifndef WORD_LADDER_PUZZLE_HPP
#define WORD_LADDER_PUZZLE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "DoublyLinkedList.hpp"

//set the global debug to true to enable more console output, to false to output minimal lines to console.
const bool gDebug = false;


//structure for our dictionary words, so we can mark them as used or not.
struct dictWord 
{
	std::string word;
	bool used = false;
};


//main class for our word ladder game
class wordLadderGame 
{
public:
	//constructor, takes a filepath.
	wordLadderGame(std::string filepath);
	//two strings function, will take them and compare them
	std::string play(std::string fromWord, std::string toWord);
	//one string function. Compares the length of the string given and finds two different strings with the same length and compares those.
	std::string play(std::string fromWord);
	//test function, lists the first 10 words of the dictionary.
	void listWords();

private:
	//declare alphabet variables
	const std::string alphabetString = "abcdefghijclmnopqrstuvwxyz";
	std::vector<char> alphabetVector;
	//declare dictionary variables
	std::ifstream dictionary;
	std::vector<dictWord> dictionaryVec;
	//file path to the dictionary, set in constructor.
	std::string filePath;
	//private play, that will be called by the public play function(s)
	std::string playPrivate(std::string fromWord, std::string toWord);
	
	//find function to look through dictionary.
	bool bianaryFind(std::string target, std::vector<dictWord>& container);
	//function to output the path to a string
	std::string outputPath(std::shared_ptr<Node<std::string>> foundNode);
	//function to change word and check against dictionary
	void findAndInsertRealWords(std::vector<char> parsedWord, std::shared_ptr<Node<std::string>> curNode, LinkedList<std::string>& list);
	//functions for switching between a vector and a string
	std::vector<char> parseString(std::string wordToParse);
	std::string vectorToString(std::vector<char> vec);
	//function to parse the file by line into a vector, used for parsing the dictionary to make the binaryfind easier.
	std::vector<dictWord> parseFileByLine(std::ifstream& file);
	//function that will generate a random word of given length
	std::string generateRandomWord(int length);
	//function that will check if the word is real
	bool isRealWord(std::string word);

	//functions to create a vector for the alphabet and for the dictionary, will be ran through the createVectors function the beginning of play game
	void createAlphabetVector();
	void createDictionaryVector();
	//runs the createAlphabetVector an dcreateDictionaryVector. Created out of not wanting to type the top two in multiple places....
	void createVectors();

};

#endif 