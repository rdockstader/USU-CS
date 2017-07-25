#ifndef	QUEUE_HPP
#define QUEUE_HPP



#include <memory>
#include<exception>

template<typename T>
struct Node
{
	Node(T t) :data(t), next(nullptr) {};
	T data;
	std::shared_ptr<Node> next;
};

template<typename T>
class Queue
{
public:
	Queue():front(nullptr), back(nullptr), size(0){};
	Queue(Queue const &);
	Queue& operator=(Queue const &);
	size_t getSize() const { return size; };
	void enqueue(T t);
	T dequeue();
	template<typename F>
	void foreach(F& f)
	{
		for (auto cur = front; cur != nullptr; cur = cur->next)
		{
			f(cur->data);
		}
	}
private:
	std::shared_ptr<Node<T>> front;
	std::shared_ptr<Node<T>> back;
	size_t size;


};

//template<typename T>
//Queue& Queue<T>::operator=(Queue const &)
//{
//
//}

template<typename T>
void Queue<T>::enqueue(T t)
{
	auto node = std::make_shared<Node<T>>(t);
	if (!back)
	{
		front = node;
		back = node;
	}
	else
	{
		back->next = node;
		back = node;
	}
	++size;
}

template<typename T>
T Queue<T>::dequeue()
{
	if (!front)
	{
		throw std::runtime_error("Dequeue from empty list");
	}
	T result = front->data;
	front = front->next;
	if (!front) back = nullptr;
	--size;
	return result;
}


#endif
