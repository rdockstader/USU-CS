#include "WordLaderPuzzle.hpp"
#include"avlTreeTemplate.hpp"

#include <sstream>
#include <random>

//Constructor to set filepath when game is created
wordLadderGame::wordLadderGame(std::string filepath)
{
	filePath = filepath;
}
//Function to list words to test if the dictionary is working with given path.
void wordLadderGame::listWords()
{
	createVectors();
	if(dictionaryVec.size() > 0)
	for (auto i = 0; i < 10; ++i)
	{
		std::cout << dictionaryVec[i].word << std::endl;
	}
	else
	{
		std::cout << "dictionary is not open." << std::endl;
	}
}

//function that will return two random words of the same length as the word entered, if just one word is entered.
std::string wordLadderGame::play(std::string fromWord)
{
	return play(generateRandomWord(fromWord.length()), generateRandomWord(fromWord.length()));
}

//Public play function, takes to strings, resets the vectors and calls the private play funciton
std::string wordLadderGame::play(std::string fromWord, std::string toWord)
{
	createVectors();
	return playPrivate(fromWord, toWord, false);
}

std::string wordLadderGame::playAStar(std::string fromWord, std::string toWord)
{
	return playPrivate(fromWord, toWord, true);
}

//private play function
std::string wordLadderGame::playPrivate(std::string fromWord, std::string toWord, bool isAStar)
{
	//output to user what path you are finding
	std::cout << "Finding path from " << fromWord << " to " << toWord << "..." << std::endl;
	//set default output to no path found, in case we are  unable to find a path
	std::string output = "No Path Found!!";
	//check to see if the word lengths match
	if (fromWord.length() != toWord.length())
	{
		std::cout << "Word lengths does not match. Please use words that are the same length" << std::endl;
		output = "none Found";
	}
	//Check to see if the fromWord is a real word
	else if (!isRealWord(fromWord))
	{
		std::cout << fromWord << " was not found in the dictionary." << std::endl;
	}
	//check to see if the toWord is a real word
	else if (!isRealWord(toWord))
	{
		std::cout << toWord << " was not found in the dictionary." << std::endl;
	}
	//if it passes all the checks, continue.
	else
	{
		//declare linked list variable
		LinkedList<std::string> wordsList;
		AvlTree<Node<std::string>> avlWordsList;
		//reset vectors after checks
		createVectors();
		//add fromWord to linked list
		wordsList.insert(fromWord);
		//set the current node to the head.
		auto curNode = wordsList.getHead();
		avlWordsList.insert(*curNode);
		//while we aren't NULL
		if (!isAStar)
		{
			while (curNode != nullptr)
			{
				//if the data in our node is our target
				if (curNode->data == toWord)
				{
					//tell the user the good news
					std::cout << "Word found!" << std::endl;
					//set the output to the path
					output = outputPath(curNode, "BRUTE");
					//output the path by default
					std::cout << output << std::endl;
					std::cout << std::endl;
					//return the output string, for external use.
					return output;
				}
				//call the function to find real words and insert them into a linked list
				findAndInsertRealWords(parseString(curNode->data), curNode, wordsList, avlWordsList, false);
				//move to the next node.
				dequeuedAmount++;
				curNode = curNode->next;
			}
		}
		else
		{
			auto parsedToWord = parseString(toWord);
			auto parsedCurWord = parseString(curNode->data);
			for (int i =0; i<parsedCurWord.size(); ++i)
			{
				if (parsedCurWord[i] == parsedToWord[i])
				{

				}
				else
					curNode->prority++;
			}
			while (curNode != nullptr)
			{
				//if the data in our node is our target
				if (curNode->data == toWord)
				{
					//tell the user the good news
					std::cout << "Word found!" << std::endl;
					//set the output to the path
					output = outputPath(curNode, "ASTAR");
					//output the path by default
					std::cout << output << std::endl;
					std::cout << std::endl;
					//return the output string, for external use.
					return output;
				}
				findAndInsertRealWords(parseString(curNode->data), curNode, wordsList, avlWordsList, true);
				if (!avlWordsList.isEmpty())
				{
					*curNode = avlWordsList.findMin();
					avlWordsList.removeMin();
				}
				else
					curNode = nullptr;

			}
		}

	}
	//output if we didnt' find anything
	std::cout << output << std::endl;
	std::cout << std::endl;
	//return that we didn't find anything
	return output;
}

void wordLadderGame::findAndInsertRealWords(std::vector<char> parsedWord, std::shared_ptr<Node<std::string>> curNode, LinkedList<std::string>& list, AvlTree<Node<std::string>>& avlList, bool isAStar)
{
	//set local variables for what iteration we are on, and how many words we have found.
	int iter = 0;
	int wordsFound = 0;
	//for each letter in the parsed word
	for (char curLetter : parsedWord)
	{
		//if debugging is turned on, output that we are searching for a word
		if(gDebug) std::cout << "Searching on word " << vectorToString(parsedWord) << ", character position " << iter + 1 << std::endl;
		//for each character in the alphabet
		for (char e : alphabetVector)
		{
			//change the letter to the next letter in the alphabet, starting with a
			parsedWord[iter] = e;
			//return the parsed word to a string
			std::string word = vectorToString(parsedWord);
			//if we find the word in the dictionary vector, and our letter isn't equal to the starting letter
			if ((bianaryFind(word, dictionaryVec)) && (e != curLetter))
			{
					//insert the word to our linked list
					list.insert(word);
					if (isAStar)
						avlList.insert(Node<std::string>(word));
					enqueuedAmount++;
					//if debugging is turned on, output the word
					if(gDebug) std::cout << " " << word << " ";
					//grab the tail (AKA, the node we just inserted)
					auto curTail = list.getTail();
					//set the "root" (the node that generated this node) to the current node
					curTail->root = curNode;
					//add one to the wordsFound variable.
					++wordsFound;
			}
			else
			{
				if(gDebug) std::cout << ".";
			}
				//replace the current letter with the proposed letter
		}
		//if debug is on, put a blank line.
		if(gDebug) std::cout << std::endl;
		//reset the parsed word back to the original word.
		parsedWord[iter] = curLetter;
		//incrament the iter variable.
		++iter;
	}
	//if debugging is turned on, output that we have finished searching for the word, how many owrds we found, and what the root was.
	if (gDebug)
	{
		std::cout << "finished searching for word: " << vectorToString(parsedWord) << ", found " << wordsFound;
		if (curNode->root)
			std::cout << " words with root " << curNode->root->data << std::endl;
		else
			std::cout << " with no root." << std::endl;
	}
}

//binary search funciton
bool wordLadderGame::bianaryFind(std::string target, std::vector<dictWord>& container)
{
	//set our begin, end and middle variables
	int begin = 0,   
		end = (container.size() - 1), //get the size -1, to account for the first place being 0       
		middle;
	//set our return value to false.
	bool found = false;

	//while we haven't found anything, and the the begining isn't less then or equal ot the end.
	while (!found && begin <= end)
	{
		//set the middle to be in the middle of begin and end.
		middle = (begin + end) / 2;     
		//if we found the target
		if (container[middle].word == target)
		{
			//if we haven't used the word yet
			if (!container[middle].used)
			{
				//set our found to true, and mark that we've used that word.
				found = true;
				container[middle].used = true;
			}
			//return that we have found the word.
			return found;
		}
		// If value is in lower half
		else if (container[middle].word > target) 
			end = middle - 1;
		// If value is in upper half
		else
			begin = middle + 1;           
	}
	//if we reach here, output the default value.
	return found;
}

std::string wordLadderGame::outputPath(std::shared_ptr<Node<std::string>> foundNode, std::string methodType)
{
	//create variables for the output string, the string stream, and create a pointer to the node we found
	std::stringstream output;
	std::vector<std::string> outputVec;
	auto curNode = foundNode;
	//set our current iteration to 0
	int iter = 0;
	//while we aren't looking at NULL
	while (curNode != nullptr)
	{
		//add the value to our output vector
		outputVec.push_back(curNode->data);
		//move on to the next node
		curNode = curNode->root;
		//incrament our iterator
		++iter;
	}
	//since our path is currently backwards, start at the end of the vector and go to 0
	for (int i = outputVec.size()-1; i >= 0; --i)
	{
		//add each element to our string stream, with a space after it.
		output << outputVec[i] << " ";
	}
	//return the string from our string stream.
	output << " " << iter << " " << methodType << " dequeued " << dequeuedAmount << " enqueued " << enqueuedAmount;
	dequeuedAmount = enqueuedAmount = 0;
	return output.str();
}

//funciton to check to see if the to/from words are real
bool wordLadderGame::isRealWord(std::string word)
{
	//do a bianary find over the dicitonary for the word.
	return bianaryFind(word, dictionaryVec);
}

//funciton to take our file, and turn it into a vector
void wordLadderGame::createDictionaryVector()
{
	//if there is anything in our vector already...
	if (dictionaryVec.size() > 0)
	{
		//if degubbing is enabled, inform the user of what we're doing.
		if(gDebug) std::cout << "Dictonary vector already created, reseting all words to used=false." << std::endl;
		//for each word in teh dictionary vector, set the word to false. Must be done by reference to change the actual word...
		for (dictWord& word : dictionaryVec)
		{
			word.used = false;
		}
	}
	//if there isn't anythign in our vector...
	else
	{
		//if debugging is enable, inform the user where we are
		if(gDebug) std::cout << "Creating Dictionary.";
		//open the file with the filepath given in the created game
		dictionary.open(filePath);
		//if debugging is enable, inform the user where we are
		if(gDebug) std::cout << ".";
		//if we successfully opened the dictionary...
		if (dictionary.is_open())
		{
			//call the file parsing funciton, and fill our dicitonary vector.
			dictionaryVec = parseFileByLine(dictionary);
			//if debugging is enable, inform the user where we are
			if(gDebug) std::cout << "." << std::endl;
			//close the file, as we are done with it.
			dictionary.close();
		}
		else
		{
			//if that failed and debugging is enabled, inform the user.
			if(gDebug) std::cout << "Dictionary did not open from path " << filePath << std::endl;
		}
	}
	
}

//function to create the alphabet vector
void wordLadderGame::createAlphabetVector()
{
	//if we've already created it
	if (alphabetVector.size() > 0)
	{
		//if debugging is enabled, inform the user where we are.
		if(gDebug) 
			std::cout << "Alphabet already parsed, continuing." << std::endl;
	}
	else
	{
		//if debugging is enabled, inform the user where we are.
		if(gDebug)
			std::cout << "Parsing Alphabet.";
		//parse the alphbetstring into a vector.
		alphabetVector = parseString(alphabetString);
		//if debugging is enabled, inform the user where we are.
		if(gDebug)
			std::cout << "." << std::endl;
	}
}

//function to generate a random word
std::string wordLadderGame::generateRandomWord(int length)
{
	//set default output to none found
	std::string output = "None Found.";
	//create a temperary dictionary, that will hold only words of the given length.
	std::vector<std::string> tempDictionary;
	//for each word in the dicitonary vector
	for (auto word : dictionaryVec)
	{
		//if the word length equals given length
		if (word.word.length() == length)
			//add that to our temp dictionary
			tempDictionary.push_back(word.word);
	}
	//if we found any
	if (tempDictionary.size() > 0)
	{
		//access the computers random device
		static std::random_device rd;
		//seed a twister with that random device
		static std::mt19937 engine(rd());
		//call a uniform distribution over the size of our dictionary
		std::uniform_int_distribution<> positionGenerator(0, tempDictionary.size() - 1);
		//set output to the temp dictionary word at the random position
		output = tempDictionary[positionGenerator(engine)];
	}
	//if we didn't find any
	else
	{	//if debuging is enabled, inform the user, give troubleshooting advice.
		if(gDebug) 
			std::cout << "Dictionary vector size isn't greater then 0, check to see if the file was able to open." << std::endl;
	}
	return output;
}

//function to create both vectors, because i call both in the same spot everytime and got tired of typing them both out....
void wordLadderGame::createVectors()
{
	createAlphabetVector();
	createDictionaryVector();
}

//funciton to parse a file by line
std::vector<dictWord> wordLadderGame::parseFileByLine(std::ifstream& file)
{
	//create vector to parse into, and empty curline variable for getLine function
	std::vector<dictWord> fileByLine;
	dictWord curLine;
	//while there is another line, add that line to the vector
	while (std::getline(file, curLine.word))
	{
		fileByLine.push_back(curLine);
	}
	//close the file, as we are now done with it
	file.close();

	//output our vector
	return fileByLine;
}


//function to parse a string
std::vector<char> wordLadderGame::parseString(std::string wordToParse)
{
	//vector of chars to hold each letter of our word
	std::vector<char> parsedWord;

	//for each character in our word
	for (char c : wordToParse)
	{
		//add the character to the vector
		parsedWord.push_back(c);
	}

	//return the vector
	return parsedWord;
}

//function to turn a vector back into a string
std::string wordLadderGame::vectorToString(std::vector<char> vec)
{
	//begin our string stream
	std::stringstream concatenatedString;
	//for each character in our vector
	for (char f : vec)
	{
		//replace the first word with the current word
		concatenatedString << f; 
	}
	//return the string
	return concatenatedString.str();

}