#include"recursionGame.hpp"

Node::Node(nodeData inputData, int sibs, std::shared_ptr<Node> lft, std::shared_ptr<Node> rt )
{
	data.value = inputData.value;
	data.childAmount = inputData.childAmount;
	siblings = sibs;
	left = lft;
	right = rt;
}

Node::Node(nodeData inputData, int sibs)
{
	data.value = inputData.value;
	data.childAmount = inputData.childAmount;
	siblings = sibs;
	left = nullptr;
	right = nullptr;
}

Node::Node(nodeData inputData)
{
	data.value = inputData.value;
	data.childAmount = inputData.childAmount;
	siblings = 0;
	left = nullptr;
	right = nullptr;
}


//constructor for value, children, and sibs
Node::Node(std::string value, int children, int sibs)
{
	data.value = value;
	data.childAmount = children;
	siblings = sibs;
	left = nullptr;
	right = nullptr;
}

//constructor for value, children
Node::Node(std::string value, int children)
{
	data.value = value;
	data.childAmount = children;
	siblings = 0;
	left = nullptr;
	right = nullptr;
}

//constructor for value
Node::Node(std::string value)
{
	data.value = value;
	data.childAmount = 0;
	siblings = 0;
	left = nullptr;
	right = nullptr;
}

//null constructor
Node::Node()
{
	data.value = "";
	data.childAmount = 0;
	siblings = 0;
	left = nullptr;
	right = nullptr;
}
