/*
Created a linked list template class that maintains all of its elements in sorted order.  
The linked list must be able to contain any type (it is a template).  In addition it must support the following:


•Insert an element (list must stay in sorted order - this is the equivalent of an amortized insertion sort) -DONE
•Remove an element (remove all elements in list with a given value - template type must be equality comparable) -DONE
•A size function that returns the number of elements in the list  --DONE
•Copy construction - this must be a deep copy - DONE
•Copy assignment - this must be a deep copy - DONE 
•Move construction - this must be a shallow copy - DONE
•Move assignment - this must be a shallow copy - DONE
•A for each function - invokes an arbitrary function (given as a parameter) on each element in the list  --DONE

Additionally you must write a program that demonstrates that your linked list class meets all requirements --DONE

*/



#include "LinkedList.hpp"

#include <cassert>
#include <iostream>

int main()
{
	
	LinkedList<int> ll;

	//insert nodes
	ll.insert(1);
	ll.insert(9);
	ll.insert(3);
	ll.insert(6);
	ll.insert(5);
	ll.insert(4);
	ll.insert(7);
	ll.insert(8);
	ll.insert(2);
	ll.insert(10);

	//foreach
	ll.forEach([](int i) {std::cout << i << std::endl; });

	//show size
	std::cout << "Size: " << ll.getSize() << std::endl;

	//delete nodes
	ll.deleteNode(3);
	ll.deleteNode(6);
	ll.deleteNode(9);

	std::cout << "Size: " << ll.getSize() << std::endl;




	//foreach
	ll.forEach([](int i) {std::cout << i << std::endl; });

	//find nodes
	auto foundNode1 = ll.findNode(2);
	auto foundNode2 = ll.findNode(8);

	std::cout << "Found Node with value of: " << foundNode1->data << std::endl;
	std::cout << "Found Node with value of: " <<foundNode2->data << std::endl;

	//copy
	LinkedList<int> ll2 = ll;

	std::cout << "The following list was copied: " << std::endl;
	ll2.forEach([](int i) {std::cout << i << std::endl; });

	
	char dummy;
	std::cin >> dummy;
}
