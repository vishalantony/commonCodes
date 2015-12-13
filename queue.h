#ifndef _MY_OWN_QUEUE_H
#define _MY_OWN_QUEUE_H

#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

struct queue_empty_exception : public exception {
	const char * what() const throw() {
		return "Queue empty!";
	}
};

template<typename T>
struct node {
	T val;
	node<T> * next;
	node(const T & v, node<T>* p = nullptr) : val(v), next(p) {}
};

template<typename T>
class queue {
private:
	node<T> * front;
	node<T> * rear;
public:
	queue(node<T> * f = nullptr, node<T> * b = nullptr) : front(f), rear(b) {}
	void insert(const T & v);		// enqueue
	T next(void) const;		// get element in front of queue
	void remove(void);		// remove element in front of queue
	bool empty(void) const;	// test if queue is empty
	~queue();
};

template<typename T>
void queue<T>::insert(const T & v) {
	node<T> * temp = new node<T>(v);
	if(front == nullptr) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}

template<typename T>
T queue<T>::next(void) const {
	try {
		if(front == nullptr) {
			throw queue_empty_exception();
		}
		return front->val;
	}
	catch(queue_empty_exception & e) {
		cerr << "An exception was caught: ";
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

template<typename T>
void queue<T>::remove(void) {
	try {
			if(front == nullptr) {
				throw queue_empty_exception();
			}
			if(front == rear) {
				delete front;
				front = rear = nullptr;
			}
			else {
				node<T>* temp = front;
				front = front->next;
				delete temp;
			}
		}
		catch(queue_empty_exception & e) {
			cerr << "An exception was caught: ";
			cerr << e.what() << endl;
			exit(EXIT_FAILURE);
		}
}

template<typename T>
bool queue<T>::empty(void) const {
	return front == nullptr;
}

template<typename T>
queue<T>::~queue() {
	node<T> * temp;
	while(front != nullptr) {
		temp = front->next;
		delete front;
		front = temp;
	}
}

#endif
