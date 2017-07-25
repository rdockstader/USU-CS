#include"scrabbleHouseRules.hpp"
#include<cassert>




void scrabbleHouseRules::playFromFile(std::ifstream& file)
{
	if (outputFrequency > 2)
		std::cout << "Enter playFromFile function" << std::endl;

	assert(file);

	beginGame();
	std::vector<std::string> wordVector;
	std::string line;
	while (getline(file, line))
	{
		if (outputFrequency > 4)
			std::cout << "line from file: " << line << std::endl;
		wordVector.push_back(line);
	}

	for (std::string word : wordVector)
	{
		if (outputFrequency > 4)
			std::cout << "Word to insert: " << word << std::endl;
		simpleInsert(word);
	}

	auto totalScore = computeTotalScore();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "-*-*-*-*-* FINAL OUTPUT *-*-*-*-*-" << std::endl;
	std::cout << "Score: " << totalScore << std::endl;
	for (int i = 0; i < wordsOfLength.size(); i++)
	{
		if (wordsOfLength[i] > 0)
			std::cout << wordsOfLength[i] << " Words of Length " << i << std::endl;
	}

	if (outputFrequency > 2)
		std::cout << "Exit playFromFile function" << std::endl;
}


void scrabbleHouseRules::resetGame()
{
	if (outputFrequency > 2)
		std::cout << "Enter resetGame function" << std::endl;
	
	scores.clear();
	usedWordTable.makeEmpty();
	wordsOfLength.clear();
	wordsOfLength.resize(50);
	
	if (outputFrequency > 2)
		std::cout << "Exit resetGame function" << std::endl;

	//outputFrequency = 4;

}










void scrabbleHouseRules::beginGame()
{
	if (beginGameShown == false)
	{
		std::cout << "Welcome to the test of the Scrabble House rules Program!" << std::endl;
		std::cout << "this program will test 5 game files, and output the results" << std::endl;
		std::cout << "according to the output freqency, set by you!" << std::endl;
		std::cout << "Please refer to the following guidelines:" << std::endl;
		std::cout << "The Output Frequency is default to 5" << std::endl;
		std::cout << "The acceptable values are 0-5" << std::endl;
		std::cout << "If you pick a value outside of the acceptable values," << std::endl;
		std::cout << "It will auto choose 4" << std::endl;
		std::cout << "Here is what each value means:" << std::endl;
		std::cout << "0. only finaly output will show" << std::endl;
		std::cout << "1. output only the total score at the end of each file" << std::endl;
		std::cout << "2. output the total score of each file, and the score of each word." << std::endl;
		std::cout << "3. same as 2, with main function location outputs" << std::endl;
		std::cout << "4. same as 3, with all function location outputs" << std::endl;
		std::cout << "5. same as 4, but will log each inserted hash key, record, variable value, etc." << std::endl;

		std::cout << "Enter the desired output frequency now..." << std::endl;
		std::cin >> outputFrequency;

		if (outputFrequency >= 0 && outputFrequency <= 5)
		{
			std::cout << "Great! You chose an Output Frequency of " << outputFrequency << std::endl;
		}
		else
		{
			std::cout << "You chose a value outside of the acceptable values! Shame!" << std::endl;
			std::cout << "Setting value back to 4" << std::endl;
			outputFrequency = 4;
			std::cout << "output frequency set to " << outputFrequency << std::endl;
		}

		if (outputFrequency > 4)
			std::cout << "resizing Words Of Lenght vector to size 50.." << std::endl;
		wordsOfLength.resize(50);
		for (auto i : wordsOfLength)
		{
			wordsOfLength[i] = 0;
		}

		if (outputFrequency > 2)
			std::cout << "Exiting beginGame function..." << std::endl;

		beginGameShown = true;
	}
}

int scrabbleHouseRules::getWordASCIIValue(std::string word)
{
	if (outputFrequency > 3)
		std::cout << "Enter getWordASCIIValue function. " << std::endl;
	auto parsedWord = parseString(word);
	
	int ASCIIValue = 0;
	if (outputFrequency > 4)
		std::cout << "Enter getWordASCIIValue Loop... " << std::endl;
	for (auto c : parsedWord)
	{
		ASCIIValue = ASCIIValue + int(c);
		if (outputFrequency > 3)
			std::cout << "ASCIIValue Current Value " << ASCIIValue <<  std::endl;
	}

	return ASCIIValue;
	if (outputFrequency > 3)
		std::cout << "Exit getWordASCIIValue function. " << std::endl;
}


void scrabbleHouseRules::simpleInsert(std::string word)
{
	if (outputFrequency > 2)
		std::cout << "Entering simpleInsert Function" << std::endl;

	int value = getWordASCIIValue(word);
	if (outputFrequency > 4)
		std::cout << "Hash value: " << value << "..." << std::endl;

	auto foundWord = usedWordTable.find(value);
	if (foundWord == NULL)
	{
		if (outputFrequency > 4)
			std::cout << "foundWord is NULL..." << std::endl;
		usedWord* uw = new usedWord();
		uw->word = word;
		usedWordTable.insert(value, uw);
		if (outputFrequency > 4)
			std::cout << "New word created: " << uw << std::endl;
	}
	else
	{
		if(outputFrequency > 4)
			std::cout << "Word has been found, increasing uses..." << std::endl;
		foundWord->uses++;
		if (outputFrequency > 4)
			std::cout << "Uses now set to " << foundWord->uses << std::endl;
	}
	
	if (outputFrequency > 4)
		std::cout << "Scoring " << word << std::endl;
		
	scores.push_back(computeWordScore(word));

	if (outputFrequency > 2)
		std::cout << "Exit simpleInsert Function" << std::endl;
}




int scrabbleHouseRules::getWordLetterValue(std::string word)
{
	if (outputFrequency > 3)
		std::cout << "Enter getWordLetterValue Function" << std::endl;
	auto parsedWord = parseString(word);
	int value = 0;
	if (outputFrequency > 4)
		std::cout << "Entering Word Value Calculation loop" << std::endl;
	for (auto c : parsedWord)
	{
		value = value + getLetterValue(c);
		if (outputFrequency > 4)
			std::cout << "	Current value: " << value << std::endl;
	}
	if (outputFrequency > 3)
		std::cout << "Exit getWordLetterValue Function" << std::endl;
	return value;
}

int scrabbleHouseRules::getLetterValue(char letter)
{
	if (outputFrequency > 3)
		std::cout << "enter getLetterValue Function (exit only displays if letter not found)" << std::endl;
	letter = tolower(letter);
	if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'l' ||
		letter == 'n' || letter == 'o' || letter == 'r' || letter == 's' ||
		letter == 't' || letter == 'u')
		return 1;
	if (letter == 'd' || letter == 'g')
		return 2;
	if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p')
		return 3;
	if (letter == 'f' || letter == 'h' || letter == 'v' || letter == 'w' ||
		letter == 'y')
		return 4;
	if (letter == 'k')
		return 5;
	if (letter == 'j' || letter == 'x')
		return 8;
	if (letter == 'q' || letter == 'z')
		return 10;
	if (outputFrequency > 3)
		std::cout << "Exit getLetterValue Function" << std::endl;
	return 0;
}

std::vector<char> scrabbleHouseRules::parseString(std::string wordToParse)
{
	if (outputFrequency > 3)
		std::cout << "Enter parseString Function" << std::endl;
	//vector of chars to hold each letter of our word
	std::vector<char> parsedWord;

	//for each character in our word
	if (outputFrequency > 4)
		std::cout << "Entering parse loop..." << std::endl;
	for (char c : wordToParse)
	{
		//add the character to the vector
		parsedWord.push_back(c);
		if (outputFrequency > 4)
			std::cout << " " << c << " was added to parsed word vector..." << std::endl;

	}

	if (outputFrequency > 3)
		std::cout << "Exit parseString Function" << std::endl;
	//return the vector
	return parsedWord;
}


int scrabbleHouseRules::getWordLengthValue(std::string word)
{
	if (outputFrequency > 3)
		std::cout << "Enter getWordLengthValue Function (only shows exit if length greater then 8)" << std::endl;
	int length = word.length();

	for (int i = 0; i < wordsOfLength.size(); i++)
		if (i == length)
			wordsOfLength[i]++;


	//returns
	if (length <= 2)
		return 0;
	if (length > 2 && length < 8)
		return length-2;

	if (outputFrequency > 3)
		std::cout << "Exit getWordLengthValue Function" << std::endl;
	return 6;
}


int scrabbleHouseRules::getBonusValue(std::string word)
{
	if (outputFrequency > 3)
		std::cout << "Enter getBonusValue Function (only shows exit if >9)" << std::endl;
	int value = getWordASCIIValue(word);
	auto hashValue = usedWordTable.find(value);
	assert(hashValue);
	auto uses = hashValue->uses;
	if (uses == 0)
		return 5;
	if (uses > 0 && uses <= 3)
		return 4;
	if (uses > 3 && uses <= 6)
		return 3;
	if (uses > 6 && uses <= 9)
		return 2;

	if (outputFrequency > 3)
		std::cout << "Exit getWordLengthValue Function" << std::endl;
	return 1;
}

int scrabbleHouseRules::computeWordScore(std::string word)
{
	if (outputFrequency > 2)
		std::cout << "Enter computeWordScore Function" << std::endl;
	int value =  getWordLetterValue(word) * getWordLengthValue(word) * getBonusValue(word);
	if (outputFrequency > 1)
		std::cout << "Value for " << word << " is " << value << "..." << std::endl;
	
	if (outputFrequency > 2)
		std::cout << "exit computeWordScore Function" << std::endl;
	return value;
}


int scrabbleHouseRules::computeTotalScore()
{
	if (outputFrequency > 2)
		std::cout << "Enter computeTotalScore Function" << std::endl;
	int totalScore = 0;
	if (outputFrequency > 4)
		std::cout << "Enter loop to calculate score..." << std::endl;
	for (auto score : scores)
	{
		totalScore = totalScore + score;
		if (outputFrequency > 4)
			std::cout << "	Current total score: " << totalScore << std::endl;
	}
	if (outputFrequency > 2)
		std::cout << "exit computeTotalScore Function" << std::endl;

	if (outputFrequency > 0)
		std::cout << "Total Score: " << totalScore << std::endl;

	return totalScore;
}