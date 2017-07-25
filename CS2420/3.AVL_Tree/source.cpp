#include"avlTreeTemplate.hpp"
#include"DoublyLinkedList.hpp"
#include"Timer.hpp"
#include"WordLaderPuzzle.hpp"


void main()
{
	
	/*-*-*-*-*-*-*PART 1*-*-*-*-*-*-*-*/
	
	//•	Add: 1 3 5 7 9 9 9 11 2 9 4 8
	AvlTree<int> tree1;
	tree1.insert(1);
	tree1.insert(3);
	tree1.insert(5);
	tree1.insert(7);
	tree1.insert(9);
	tree1.insert(9);
	tree1.insert(9);
	tree1.insert(11);
	tree1.insert(2);
	tree1.insert(9);
	tree1.insert(4);
	tree1.insert(8);
	//(now print tree)
	std::cout << tree1.toString() << std::endl;
	//•	Remove 7 9 
	tree1.remove(7);
	tree1.remove(9);
	// (now print tree)
	std::cout << tree1.toString() << std::endl;
	// Add 30 50 30 30 15 18
	tree1.insert(30);
	tree1.insert(50);
	tree1.insert(30);
	tree1.insert(30);
	tree1.insert(15);
	tree1.insert(18);
	// (now print tree)
	std::cout << tree1.toString() << std::endl;
	//Remove Min (first)
	tree1.removeMin();
	// (now print tree)
	std::cout << tree1.toString() << std::endl;
	//Remove Min (second)
	tree1.removeMin();
	// (now print tree)
	std::cout << tree1.toString() << std::endl;
	//Remove Min (third)
	tree1.removeMin();
	// (now print tree)
	std::cout << tree1.toString() << std::endl;
	// add 17
	tree1.insert(17);
	// (now print tree)
	std::cout << tree1.toString() << std::endl;
	//END PART ONE */


	/*-*-*-*-*-*-*CODE FROM ASSIGNMENT ONE FOR REFERENCE*-*-*-*-*-*-*-*/ 
	const int RANDOMCT = 1;
	wordLadderGame g("D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\3.AVL_Tree\\Resources\\dictionary.txt");
	g.listWords();  //Lists the first ten words in the dictionary as a test.
	g.play("this", "those");
	g.play("vicki", "allan");
	g.play("oops", "pops");
	g.play("happily", "angrily");
	g.play("slow", "fast");
	g.play("stone", "money");
	for (int i = 0; i < RANDOMCT; i++)
		g.play("flute");  //if two arguments are not provided, randomly pick both strings.  Use the length of provided argument as length of strings
	//END CODE FROM ASSIGNMENT ONE */

	/*-*-*-*-*-*-*-*PART TWO*-*-*-*-*-*-*-*-*-*/
	wordLadderGame g2("D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\3.AVL_Tree\\Resources\\dictionary.txt");
	g2.listWords();
	     g2.play("kiss", "woof");
	g2.playAStar("kiss", "woof");
	     g2.play("cock", "numb");
	g2.playAStar("cock", "numb");
	     g2.play("jura", "such");
	g2.playAStar("jura", "such");
	     g2.play("stet", "whey");
	g2.playAStar("stet", "whey");
		 g2.play("doctor", "lawyer");
	g2.playAStar("doctor", "lawyer");
	//END PART TWO */

	/*-*-*-*-*-*leave console open, if running from VS*-*-*-*-*-*/
	std::string dummy;
	std::cout << "Press Enter key to continue." << std::endl;
	std::getline(std::cin ,dummy);
	// END */


}
