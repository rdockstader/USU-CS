#include <memory>

template<typename T>
struct Node
{
	Node(T t) :data(t), left(nullptr), right(nullptr){}
	T data;
	std::shared_ptr<Node> right;
	std::shared_ptr<Node> left;
};

template <typename T>
void zig(std::shared_ptr<Node<T>> &tree) //rotate to the right
{
	if (!tree) return;
	if (!tree->right) return;
	auto A = tree;
	tree = tree->right;
	A->right = tree->left;
	tree->left = A;
}

template <typename T>
void zag(std::shared_ptr<Node<T>> &tree) //rotate to the left
{
	if (!tree) return;
	if (!tree->right) return;
	auto A = tree;
	tree = tree->left;
	A->left = tree->right;
	tree->right = A;
}


int main()
{

}


/*
improving this code with the "red/black" sorting method

1. nullptr is black
2. root is black
3. on insertion nodes are red
4. red nodes has black children --THIS IS WHERE THE MAGIC HAPPENS
5. all paths from root to leaves have the same number of black nodes (ALMOST FOGOTTEN)
        -these means the shortest posible path is all black nodes
		-the longest would be double that (red, black, red, black, red, black, etc.)
		-this is good enough to grant us order log(n) because at most we are off by a constant
		factor of 2.

When we insert into our tree it starts as a regular binary tree.

A few cases that we have to watch out for

case 1:
-insert a root node, and it will insert as red. However, we have to have it black, so we have to make sure it is black at the end of all changes
-this will be the ONLY place that you just make a red node a black node. other times we will change colors, but that will generally require a swap

Case 2:
-If you insert a red node, and it's parent is black there isn't anything you have to do.

case 3 & 4:
-if we have a zig zag, we need to do a rotation (left or right)
     -we cant have a left red child of a right red parent (or vice versa), basically we just have to make it straight.

Case 5:
-once we are in the situation described above (black followed by red followed by red in a straight line)
	-if the "uncle" (the node going to the other direction) node is red we don't need to change the structure, we just have to change the color of
	the uncle and the parent
	-if the uncle node is black, then we will have to do do a rotation, so the parent goes to the uncle and the uncle moves down a space. Then 
	you will have to recolor the new parent node.


*/
