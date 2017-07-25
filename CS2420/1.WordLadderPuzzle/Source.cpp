#include "WordLaderPuzzle.hpp"
#include "DoublyLinkedList.hpp"
#include "Timer.hpp"

int main()
{
	const int RANDOMCT = 100;
	wordLadderGame g("C:\\Users\\ryanl\\Documents\\CS2420\\CS2420\\1.WordLadderPuzzle\\Resources\\dictionary.txt");
	g.listWords();  //Lists the first ten words in the dictionary as a test.
	g.play("this", "those");
	g.play("vicki", "allan");
	g.play("oops", "pops");
	g.play("happily", "angrily");
	g.play("slow", "fast");
	g.play("stone", "money");
	for (int i = 0; i < RANDOMCT; i++)
		g.play("flute");  //if two arguments are not provided, randomly pick both strings.  Use the length of provided argument as length of strings
	char dummy;
	std::cout << "press any key, then enter to exit program." << std::endl;
	std::cin >> dummy;
}





//const bool isTiming = true;
//
//
//void main()
//{
//	// /*Desktop*/ "D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\1.WordLadderPuzzle\\Resources\\dictionary.txt"
//	//*Laptop*/ "C:\\Users\\ryanl\\Documents\\CS2420\\CS2420\\1.WordLadderPuzzle\\Resources\\dictionary.txt"
//	wordLadderGame game("C:\\Users\\ryanl\\Documents\\CS2420\\CS2420\\1.WordLadderPuzzle\\Resources\\dictionary.txt");
//	timer myTimer;
//	if (isTiming)
//		myTimer.startTimer();
//	std::string output = game.play("slow", "fast");
//	if (isTiming)
//		myTimer.endTimer();
//	std::cout << "Finished with path: " << output;
//	if (isTiming)
//		std::cout << " in " << myTimer.duration() << " Seconds." << std::endl;
//	else
//		std::cout << std::endl;
//	char dummy;
//	std::cin >> dummy;
//} 