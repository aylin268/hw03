#include "MyStack.h"





//set head to nullptr(enpty liked List )
MyStack::MyStack(){
    head=nullptr;
}

MyStack::~MyStack(){
    clear();
}


void MyStack::clear(){
    while(!is_empty()){
        pop();
    }
}



double MyStack::pop(){
    if(is_empty()){
        throw std::underflow_error("Stack is empty");;
    }

    double val = head -> value;
    Node* temp = head;
    head = head->next;
    delete temp;
    return val;
    
} 

void MyStack::push(double value) {
    Node* newNode = new Node{value, head};
    head = newNode;
} //adds to top


double MyStack::top() const{
    if(is_empty()){
        throw std::underflow_error("Stack is empty");
    }
    return head->value;
} //returns top value


bool MyStack::is_empty() const{
    return head == nullptr;
}

