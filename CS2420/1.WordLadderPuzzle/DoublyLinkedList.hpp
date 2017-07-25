#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <string>
#include <memory>
#include <exception>
#include <algorithm>

//template node structure
template<typename T>
struct Node
{
	//constructor. Needs some type of data, everything else is set to null
	Node(T t) :data(t), next(nullptr), prev(nullptr), root(nullptr) {};
	T data;
	std::shared_ptr<Node> next;
	std::shared_ptr<Node> prev;
	std::shared_ptr<Node> root;
};

//template lenked list class
template<typename T>
class LinkedList
{
public:
	//constructor to set default values.
	LinkedList() : head(nullptr), tail(nullptr), size(0) {};
	//clone function
	LinkedList(LinkedList const & other) :head(clone(other.head)) {};
	//reference is default.
	LinkedList(LinkedList&&) = default;
	//set = operator.
	LinkedList& operator=(LinkedList const & other) { head = head(clone(other.head)); };
	//function to return the size
	size_t getSize() const { return size; };
	//funciton to insert
	void insert(T t);
	//function to get a pointer to the head
	std::shared_ptr<Node<T>> getHead();
	//function to get a pointer to the tail.
	std::shared_ptr<Node<T>> getTail();
	//function to set the fail.
	void setTail(std::shared_ptr<Node<std::string>> pointTailTo);
	//forEach node function.
	template<typename F>
	void forEach(F& f)
	{
		for (auto cur = head; cur != nullptr; cur = cur->next)
		{
			f(cur->data);
		}
	}
private:
	//insert after something. called by insert
	void insertAfter(T const & value, std::shared_ptr<Node<T>> location);

	//private variables of head, tail, and size.
	std::shared_ptr<Node<T>> head;
	std::shared_ptr<Node<T>> tail;
	size_t size;
	//function to clone. called by a constructor.
	std::shared_ptr<Node<T>> clone(std::shared_ptr<Node<T>> list)
	{
		if (!list) return nullptr;
		auto node = std::make_shared<Node<T>>(list->data);
		node->next = clone(list->next);
		return node;
	}

};

//gethead function
template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::getHead()
{
	try
	{
		//if head doesn't exist, throw an error.
		if (head == nullptr)
			throw;
	}
	catch(...)
	{
		//inform user
		std::cout << "Head is a null poiter" << std::endl;
	}
	//return the head.
	return head;
}

//function to return tail.
template<typename T>
std::shared_ptr<Node<T>> LinkedList<T>::getTail()
{
	try
	{
		//if tail is null throw
		if (tail == nullptr)
			throw;
	}
	catch (...)
	{
		//inform user
		std::cout << "Head is a null poiter" << std::endl;
	}
	//return tail.
	return tail;
}

//funciton to set the tail.
template<typename T>
void LinkedList<T>::setTail(std::shared_ptr<Node<std::string>> pointTailTo)
{
	//set the tail.
	tail = pointTailTo;
}

//insert function
template<typename T>
void LinkedList<T>::insert(T t)
{
	//if no head, set head and tail to new pointer.
	if (!head)
	{
		head = std::make_shared<Node<T>>(t);
		tail = std::make_shared<Node<T>>(t);
		++size;
	}
	//otherwise
	else
	{
		//set our current node to the head
		auto node = head;
		//for each node in the list...
		for (size_t i = 0; i < getSize(); ++i)
		{
			//if there isn't a next node
			if (!node->next)
			{
				//insert the node at the end
				insertAfter(t, node);
				break;
			}
			//move to the next node
			node = node->next;
		}
	}
}

//node to insert after the current node
template<typename T>
void LinkedList<T>::insertAfter(T const & value, std::shared_ptr<Node<T>> location)
{
	//if it's null, jsut return...
	if (!location) return;
	//create a new node
	auto node = std::make_shared<Node<T>>(value);
	//set the locations next to the new nodes next
	node->next = location->next;
	//set the locations next to the node
	location->next = node;
	//set the nodes previous to the location
	node->prev = location;
	//set the tail to the node
	tail = node;
	//add to the size.
	++size;
}
#endif 
