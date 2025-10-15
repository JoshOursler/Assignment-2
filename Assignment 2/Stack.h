#pragma once
#include <vector>	//To use std::vector
class Stack
{
public:
	Stack() {}; //Constructor
	void push(int value); //Push value onto stack
	int pop(); //Pop value off stack and return it
	//Destructor
	~Stack() {
		for (size_t i = 0; i < elements.size(); i++) {
			elements.pop_back();
		}
	};
private:
	std::vector<int> elements; //Vector to hold stack elements
};

