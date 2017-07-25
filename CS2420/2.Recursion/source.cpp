#include "recursionGame.hpp"
#include<fstream>

/*
UNFINISHED:
(1) buildFromPrefix
(2) the third one
(3) Common Ancestor
*/

/*
void main()
{
	//std::ifstream inf("C:\\Users\\ryanl\\Documents\\githubcs2420\\2.Recursion\\Resources\\prog2In.txt"); //laptop
	//std::ofstream outf("C:\\Users\\ryanl\\Documents\\githubcs2420\\2.Recursion\\Resources\\prog2Out.txt"); //laptop
	std::ifstream inf("D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\2.Recursion\\Resources\\prog2In.txt"); //desktop
	std::ofstream outf("D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\2.Recursion\\Resources\\prog2Out.txt"); //desktop
	//outf.open("prog2Out.txt");
	//inf.open("prog2In.txt");
	assert(inf);
	assert(outf);
	const int SIZE = 12;
	Tree t[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		t[i].buildFromPrefix(inf);
	}
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Tree" << i << "\n" << t[i].printTree();
		//outf << "Tree" << i << "\n" << t[i].printTree();
		//std::cout << "FRINGE " << t[i].fringe() << std::endl;
	}
	//finds
	if (t[0].findWord("luck") == NULL) std::cout << "dins not found\n";
	std::cout << "enter any character, and then press enter to exit." << std::endl;
	char dummy;
	std::cin >> dummy;
}
//*/


//*
int main()
{
	//declare file variables
	//std::ifstream inf("prog2Out.txt");
	//std::ofstream outf("prog2In.txt");
	std::ifstream inf("D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\2.Recursion\\Resources\\prog2In.txt"); //desktop
	std::ofstream outf("D:\\Users\\Ryan\\Documents\\CS2420\\CS2420\\2.Recursion\\Resources\\prog2Out.txt"); //desktop
	//assert the files exist
	assert(inf);
	assert(outf);
	//size variable
	const int SIZE = 12;
	//array of trees
	Tree t[SIZE];
	//for each tree, build a tree.
	for (int i = 0; i < SIZE; i++)
      t[i].buildFromPrefix(inf);
	//print the tree to the output file, and the console
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Tree" << i << "\n" << t[i].printTree();
		outf << "Tree" << i << "\n" << t[i].printTree ();
		std::cout << "FRINGE " <<t[i].fringe() << std::endl;
	}
	//try find word.
	if (t[0].findWord("dins") == NULL) 
		std::cout << "dins not found\n";
	if (t[0].findWord("tone") == NULL) 
		std::cout << "tone not found\n";
	t[0].upCase();
	std::cout << t[0].printTree();
	if (t[0].findWord("guck") == NULL) std::cout << "guck not found\n";
	if (t[0].findWord("TONE") == NULL) std::cout << "TONE not found\n";

	t[7].makeEmpty();
	std::cout << "empty tree fringe " << t[7].fringe() << std::endl;

	for (int i = 0; i < SIZE; i++){
		std::cout << "NodesInLevel 2 of tree" << i << " " << t[i].nodesInLevel(2) << std::endl;
	}
	std::cout << " TREE 3\n" <<  t[3].printTree();
	std::cout << " TREE 10\n" << t[10].printTree();
	t[3] = t[10].clone();
	t[3].upCase();
	std::cout << " TREE 3 cloned\n" << t[3].printTree();
	std::cout << " TREE 10\n" << t[10].printTree();

	for (int i = 0; i < SIZE; i++)
		for (int j = i + 1; j < SIZE; j++)
			if (t[i].isIsomorphic( t[j])) std::cout << "Two trees are isomorphic Tree:" << i << " Tree:" << j << std::endl;
	//std::cout << "Made it here" << std::endl;
	std::cout << "Common Ancestor of lade and gunk " << t[2].commonAncestor("lade", "gunk") << std::endl;
	std::cout << "Common Ancestor of luce and gunk " << t[1].commonAncestor("luce", "gunk") << std::endl;
	std::cout << "Common Ancestor of lick and dene " << t[1].commonAncestor("lick", "dene") << std::endl;
	std::cout << "Common Ancestor of lick and muck " << t[1].commonAncestor("lick", "muck") << std::endl;
	char c;
	std::cin >> c;
	outf.close();
}

//*/