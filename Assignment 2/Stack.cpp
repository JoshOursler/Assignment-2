#include "Stack.h"
#include <stdexcept> //To use std::out_of_range

//Define stack member functions
//Push value onto stack
void Stack::push(int value) {
	elements.push_back(value);
};

//Pop value off stack and return it
int Stack::pop() {
	if (elements.empty()) {
		throw std::out_of_range("Stack is empty");
	}
	int value = elements.back();
	elements.pop_back();
	return value;
};