#ifndef MYSTACK_H
#define MYSTACK_H

#include "Stack.h"
#include <stdexcept>


//add to the stack 
//remove from stack 
//check if its empty 


class MyStack: public Stack {
public:
	MyStack();
	~MyStack();

	double pop() override ; //removes and return the top value 
	void push(double value) override; //adds to top
	double top() const override; //returns top value
	bool is_empty() const override;
	void clear() override;


	//linked List 
	private:
		struct Node{
			double value;
			Node* next;
		};

		Node* head;
};

#endif
