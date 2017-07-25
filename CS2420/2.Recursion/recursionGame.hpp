#ifndef RECURSION_GAME_HPP
#define RECURSION_GAME_HPP

#include<fstream>
#include<iostream>
#include<memory>
#include<cassert>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

const bool gDebug = true;


struct nodeData
{
	int childAmount;
	std::string value;
};

struct Node
{
	//constructors
	Node(nodeData inputData, int sibs, std::shared_ptr<Node> lft, std::shared_ptr<Node> rt);
	Node(nodeData inputData, int sibs);
	Node(nodeData inputData);
	Node(std::string value, int children, int sibs);
	Node(std::string value, int children);
	Node(std::string value);
	Node(); 
	//value of the node
	nodeData data;
	//left child (eldest child)
	std::shared_ptr<Node> left;
	//right child (siblings)
	std::shared_ptr<Node> right;
	//parent
	std::shared_ptr<Node> parent;
	//amount of subtree nodes
	int siblings;
	int subTreeNodeAmount = 1; //(3) subtree count, including self. 
};


class Tree
{
public:
	Tree() : root(nullptr) {}
	Tree(std::shared_ptr<Node> root): root(root) {}
	std::shared_ptr<Node> getRoot();
	std::shared_ptr<Node> buildFromPrefix(std::ifstream& inf);
	std::shared_ptr<Node> findWord(std::string target);
	std::string printTree();
	std::string toPreorder();
	Tree clone();
	void upCase() { return upCase(root); }
	void makeEmpty();
	int fringe() { return fringe(root); }
	int nodesInLevel(int level) { return nodesInLevel(level, root); }
	bool isIsomorphic(Tree &t2) { return isIsomorphic(root, t2.getRoot()); } 
	std::string commonAncestor(std::string s1, std::string s2); 
	std::shared_ptr<Node> commonAncestor(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2);
private:
	bool isIsomorphic(std::shared_ptr<Node> r1, std::shared_ptr<Node> r2);
	int nodesInLevel(int level, std::shared_ptr<Node> curNode);
	int fringe(std::shared_ptr<Node>);
	void upCase(std::shared_ptr<Node> curNode);
	char upCaseSwitch(char &c);
	std::shared_ptr<Node> clone(std::shared_ptr<Node> parent, std::shared_ptr<Node> curNode);
	std::string toPreorder(std::shared_ptr<Node> curNode);
	std::string printTree(std::string indent, std::shared_ptr<Node> curNode);
	std::shared_ptr<Node> root;
	std::shared_ptr<Node> curNode = root;
	std::shared_ptr<Node> previousNode = nullptr;
	std::shared_ptr<Node> findWord(std::string target, std::shared_ptr<Node> curNode);
	std::shared_ptr<Node> buildFromPrefix(std::shared_ptr<Node> curNode, std::ifstream& inf);
};

#endif 
