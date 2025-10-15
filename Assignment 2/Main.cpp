#include "Stack.h"
#include <iostream>

int main() {
	//Create a stack object
	Stack numbers;

	//Check the stack is empty or not
	try {
		int temp = numbers.pop();
		std::cout << "Stack is not empty" << std::endl;
		numbers.push(temp);
	}
	catch (const std::out_of_range& e) {
		std::cout << "Stack is empty" << std::endl;
	}

	//Insert some integer values onto the stack
	numbers.push(64);
	numbers.push(69);
	numbers.push(28);
	numbers.push(54);
	numbers.push(24);

	//Remove an element from the stack
	std::cout << "Popped value: " << numbers.pop() << std::endl;

	//Find the Top of the stack
	int temp = numbers.pop();
	std::cout << "Top of the stack: " << temp << std::endl;
	numbers.push(temp);

	//Find average value of the stack elements
	Stack tempStack;
	int sum = 0;
	int count = 0;
	int value;
	while (true) {
		try {
			int value = numbers.pop();
			sum += value;
			count++;
			tempStack.push(value);
		}
		catch (const std::out_of_range& e) {
			break;
		}
	}
	std::cout << "Average value of stack elements: " << static_cast<double>(sum) / count << std::endl;

	//Restore the original stack
	while (true) {
		try {
			int value = tempStack.pop();
			numbers.push(value);
		}
		catch (const std::out_of_range& e) {
			break;
		}
	}
	return 0;
};