#pragma once
#include <cstddef> // for size_t and nullptr

//Create a tempplate struct for a node in a singly linked list
template <typename Item_Type>
struct Node {
	Item_Type data;
	Node* next;

	//Constructor
	Node(const Item_Type& data_item, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {};
};

//Class template definition for a singly linked list
template <typename Item_Type>
class SinglyLinkedList {
public:
	//Declare member functions
	//Constructor
	SinglyLinkedList() : head(nullptr), tail(nullptr), num_items(0) {};

	//Push an item to the front of the list
	void push_front(const Item_Type& item);

	//Push an item to the back of the list
	void push_back(const Item_Type& item);

	//Pop an item from the front of the list
	void pop_front();

	//Pop an item from the back of the list
	void pop_back();

	//Reference the front item of the list
	Item_Type& front();

	//Reference the back item of the list
	Item_Type& back();

	//Check if the list is empty
	bool empty() const;

	//Insert an item at a specific position in the list
	void insert(size_t index, const Item_Type& item);

	//Remove an item from a specific position in the list
	bool remove(size_t index);

	//Find the index of a specific item in the list
	size_t find(const Item_Type& item);
private:
	//Data members
	Node<Item_Type>* head; // Pointer to the head of the list
	Node<Item_Type>* tail; // Pointer to the tail of the list
	size_t num_items; // Number of items in the list
};