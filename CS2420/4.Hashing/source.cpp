#include"HashTable.hpp"
#include"scrabbleHouseRules.hpp"
#include<iostream>
#include<string>
#include<memory>


//need to get values to be the same as the ones on piazza
//need to recreated the hashing function.


/*-*-*-*-*-*-PART TWO-*-*-*-*-*-*-*/

void main()
{
	//initialize variables
	std::string filePath = "D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\4.Hashing\\Resources\\game";
	scrabbleHouseRules game;
	//game 0
	std::string filePath0 = filePath + "0.txt";
	std::ifstream file0(filePath0);
	game.playFromFile(file0);
	game.resetGame();
	//game 1
	std::string filePath1 = filePath + "1.txt";
	std::ifstream file1(filePath1);
	game.playFromFile(file1);
	game.resetGame();
	// game 2
	std::string filePath2 = filePath + "2.txt";
	std::ifstream file2(filePath2);
	game.playFromFile(file2);
	game.resetGame();
	// game 3
	std::string filePath3 = filePath + "3.txt";
	std::ifstream file3(filePath3);
	game.playFromFile(file3);
	game.resetGame();
	// game 4
	std::string filePath4 = filePath + "4.txt";
	std::ifstream file4(filePath4);
	game.playFromFile(file4);
	game.resetGame();



	char dummy;
	std::cout << "Choose any character to finish" << std::endl;
	std::cin >> dummy;
}



/* test 2
void main()
{
	HashTable<int, std::string> testTable = 10;
	auto* s = new std::string("test");
	auto val = *s;
	int value = atoi(val.c_str());
	testTable.insert(value, new std::string("test"));
}
*/







/* PART ONE  
void main()
{
	//part one
	//initialize
	HashTable<int, std::string> testTable = 10; //test setting the size of the hash table
	//test inserts
	testTable.insert(10, new std::string("test"));
	testTable.insert(11, new std::string("test2"));
	testTable.insert(1, new std::string("test3"));
	testTable.insert(10, new std::string("test4")); //wont insert with same key.
	//output inserts
	std::cout << testTable.toString() << std::endl;
	//test deletes
	testTable.remove(10);
	testTable.remove(11);
	//output deletes
	std::cout << testTable.toString() << std::endl;
	//remove item that doesn't exsist
	testTable.remove(-1); 
	testTable.remove(10000);
	testTable.remove(0);
	//output after false removes
	std::cout << testTable.toString() << std::endl;
	//add a crap ton of items
	testTable.insert(0, new std::string("test0"));
	testTable.insert(1, new std::string("test1"));
	testTable.insert(2, new std::string("test2"));
	testTable.insert(3, new std::string("test3"));
	testTable.insert(4, new std::string("test4"));
	testTable.insert(5, new std::string("test5"));
	testTable.insert(6, new std::string("test6"));
	testTable.insert(7, new std::string("test7")); 
	testTable.insert(8, new std::string("test8"));
	testTable.insert(9, new std::string("test9"));
	testTable.insert(10, new std::string("test10"));
	testTable.insert(11, new std::string("test11")); 
	testTable.insert(12, new std::string("test12"));
	testTable.insert(13, new std::string("test13"));
	testTable.insert(14, new std::string("test14"));
	testTable.insert(15, new std::string("test15")); 
	//output after over insertion
	std::cout << testTable.toString() << std::endl; //size grows a lot.


	char dummy;
	std::cin >> dummy;
	
}

*/