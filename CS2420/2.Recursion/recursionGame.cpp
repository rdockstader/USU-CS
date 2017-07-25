#include"recursionGame.hpp"



//get root function, just in case
std::shared_ptr<Node> Tree::getRoot()
{
	return root;
}

//(1)begin build from prefix functions...
std::shared_ptr<Node> Tree::buildFromPrefix(std::ifstream& inf)
{
	std::string word;
	int children;
	inf >> word >> children;
	root = std::make_shared<Node>(word, children);
	buildFromPrefix(root, inf);

	return root;
}

std::shared_ptr<Node> Tree::buildFromPrefix(std::shared_ptr<Node> curNode, std::ifstream& inf)
{
	std::string word;
	int children;
	inf >> word >> children;
	//if we have reached the end of the line, return.
	//	nullptr;

	auto newNode = std::make_shared<Node>(word, children);
	newNode->parent = curNode;
	if (curNode->data.childAmount > 0)
	{
		newNode->siblings = curNode->data.childAmount - 1;
		curNode->left = buildFromPrefix(newNode, inf);
	}
	if (curNode->siblings > 0)
	{
		newNode->siblings = curNode->siblings - 1;
		curNode->right = buildFromPrefix(newNode, inf);
	}
	return newNode;
}
//end build from prefix functions...


//(2)begin find word functions....
std::shared_ptr<Node> Tree::findWord(std::string target)
{
	return findWord(target, root);
}

std::shared_ptr<Node> Tree::findWord(std::string target, std::shared_ptr<Node> curNode)
{
	if (curNode == nullptr)
	{
		return nullptr;
	}
	if (curNode->data.value == target)
	{
		return curNode;
	}
	return std::max(findWord(target, curNode->left), findWord(target, curNode->right));
}
//end find word functions


//(4)begin print tree functions
std::string Tree::printTree()
{
	return printTree("", root);

}


std::string Tree::printTree(std::string indent, std::shared_ptr<Node> curNode)
{
	std::stringstream ss;
	if ( curNode == nullptr)
	{
		return "";
	}
	else
	{
		ss << indent << curNode->data.value << " [" << curNode->subTreeNodeAmount << ":" << curNode->data.childAmount << "]" <<  std::endl;
	}
	auto st = ss.str();
	return st + printTree(indent + "", curNode->right) + printTree(indent + "  ", curNode->left);

}
//end print tree functions



//(5) begin toPreorder functions....

std::string Tree::toPreorder()
{
	return toPreorder(root);
}

std::string Tree::toPreorder(std::shared_ptr<Node> curNode)
{
	if (curNode == nullptr)
	{
		return "";
	}
	return curNode->data.value + " " +  std::to_string(curNode->data.childAmount) + " " + toPreorder(curNode->left) + toPreorder(curNode->right);
}


//end toPreorder functions....


//(6) begin clone functions...

Tree Tree::clone()
{
	return Tree(clone(nullptr, root));
}

std::shared_ptr<Node> Tree::clone(std::shared_ptr<Node> parent, std::shared_ptr<Node> curNode)
{
	if (parent == nullptr)
		return nullptr;
	clone(curNode, curNode->left);
	clone(curNode, curNode->right);
	return std::make_shared<Node>(parent->data, parent->siblings, parent->left, parent->right);
}

// end clone functions...


//(7) begin upCase functions...

void Tree::upCase(std::shared_ptr<Node> curNode)
{
	if (curNode == nullptr) return;
	for (auto &c : curNode->data.value)
	{
		upCaseSwitch(c);
	}
	upCase(curNode->left);
	upCase(curNode->right);
}


char Tree::upCaseSwitch(char &c)
{
	switch (c)
	{
	case 'a':
		c = 'A';
		break;
	case 'b':
		c = 'B';
		break;
	case 'c':
		c = 'C';
		break;
	case 'd':
		c = 'D';
		break;
	case 'e':
		c = 'E';
		break;
	case 'f':
		c = 'F';
		break;
	case 'g':
		c = 'G';
		break;
	case 'h':
		c = 'H';
		break;
	case 'i':
		c = 'I';
		break;
	case 'j':
		c = 'J';
		break;
	case 'k':
		c = 'K';
		break;
	case 'l':
		c = 'L';
		break;
	case 'm':
		c = 'M';
		break;
	case 'n':
		c = 'N';
	case 'o':
		c = 'O';
		break;
	case 'p':
		c = 'P';
		break;
	case 'q':
		c = 'Q';
		break;
	case 'r':
		c = 'R';
		break;
	case 's':
		c = 'S';
		break;
	case 't':
		c = 'T';
		break;
	case 'u':
		c = 'U';
		break;
	case 'v':
		c = 'V';
		break;
	case 'w':
		c = 'W';
		break;
	case 'x':
		c = 'X';
		break;
	case 'z':
		c = 'Z';
		break;
	default:
		break;
	}

	return c;
}

// end upCase functions....

// (8) begin Make empty functions....

void Tree::makeEmpty()
{
	root = nullptr;
	//smart pointers automatically delete themselves when nothing is pointing at them,
	//meaning that if i set root to nullptr, my tree is deleted from memory layer by layer,
	//since the root pointer is the only stored variable and nothing is pointing to it anymore. 
	//To do this recursively, i would have to recurse
	//down until i hit a null pointer, and then delete each node on my way up (exit path),
	//starting with the furthest down right node, and going up until i delete root. But,
	//why do more work then you need to :) 
}

// end make empty functions....



// (9) begin fringe function.

int Tree::fringe(std::shared_ptr<Node> curNode)
{
	if (curNode == nullptr)
		return 0;
	if (curNode->left == nullptr && curNode != nullptr)
		return 1;
	return fringe(curNode->left) + fringe(curNode->right);
	return 0;
}


// end fringe functions...

//(10) begin nodesInlevel functions...

int Tree::nodesInLevel(int level, std::shared_ptr<Node> curNode)
{
	if (curNode == nullptr)
		return 0;
	
	if (nodesInLevel(level, curNode->left) == level)
		return 1 + nodesInLevel(level, curNode->right);
	
	return 1 + nodesInLevel(level, curNode->left);
}

// end nodesInLevel functions...


// (11) begin isomorphic

bool Tree::isIsomorphic(std::shared_ptr<Node> r1, std::shared_ptr<Node> r2)
{
	//reach bottom at the same time, or both roots are null, then true
	if (r1 == NULL && r2 == NULL)
		return true;
	//reached bottom at different times then false
	if (r1 == NULL || r2 == NULL)
		return false;
	//recurse over each node
	return (isIsomorphic(r1->left, r2->left) && isIsomorphic(r1->right, r2->right));
}

//end isomorphic

// (12) begin common ancestor

std::string Tree::commonAncestor(std::string s1, std::string s2)
{
	auto foundNode = commonAncestor(findWord(s1), findWord(s2));
	if (foundNode)
	{
		return foundNode->data.value;
	}
	return "No common Ancestor found!";
	
}


std::shared_ptr<Node> Tree::commonAncestor(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2)
{
	return nullptr;
}

//end common ancestor