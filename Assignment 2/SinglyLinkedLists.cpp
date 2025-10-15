#include "SinglyLinkedLists.h"
#include <iostream>

//Define the Sinngly Linked List Member Functions
//Push an item to the front of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::push_front(const Item_Type& item) {
	//Check if the list is empty, if so create a new node and set head and tail to it
	if (empty()) {
		head = new Node<Item_Type>(item);
		tail = head;
	}
	//If the list is not empty, create a new node and set head to it
	else {
		Node<Item_Type>* new_node = new Node<Item_Type>(item, head);
		head = new_node;
	}
	num_items++;	//Increment the number of items in the list
};

//Push an item to the back of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::push_back(const Item_Type& item) {
	//Check if the list is empty, if so create a new node and set head and tail to it
	if (empty()) {
		tail = new Node<Item_Type>(item);
		head = tail;
	}
	//If the list is not empty, create a new node and set tail to point to it
	else {
		Node<Item_Type>* new_node = new Node<Item_Type>(item);
		tail->next = new_node;
		tail = new_node;
	}
	num_items++;	//Increment the number of items in the list
};

//Pop an item from the front of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::pop_front() {
	//Check if the list is empty, if so return an error
	if (empty()) {
		std::cerr << "Error: List is empty" << std::endl;
	}

	// Delete the front node and update head to point to the next node
	Node<Item_Type>* temp = head;
	head = head->next;
	delete temp;

	//Decrease the number of items in the list
	num_items--;
};

//Pop an item from the back of the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::pop_back() {
	//Check if the list is empty, if so return an error
	if (empty()) {
		std::cerr << "Error: List is empty" << std::endl;
	}

	//If there was only one item in the list, set head and tail to null
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	} else {
		//Reassign tail to the previous node
		Node<Item_Type>* current_node = head;
		while (current_node->next != tail) {
			current_node = current_node->next;
		}
		tail = current_node;
		tail->next = nullptr;
		delete current_node;
	}
	
	//Decrease the number of items in the list
	num_items--;
};

//Reference the front item of the list
template <typename Item_Type>
Item_Type& SinglyLinkedList<Item_Type>::front() {
	return head->data;
};

//Reference the back item of the list
template <typename Item_Type>
Item_Type& SinglyLinkedList<Item_Type>::back() {
	return tail->data;
};

//Check if the list is empty
template <typename Item_Type>
bool SinglyLinkedList<Item_Type>::empty() const {
	return num_items == 0;
};

//Insert an item at a specific position in the list
template <typename Item_Type>
void SinglyLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
	//Check if the index is valid
	if (index > num_items) {
		std::cerr << "Error: Index out of bounds" << std::endl;
		return;
	}

	//If the index is 0, push the item to the front of the list
	if (index == 0) {
		push_front(item);
		return;
	}

	//If the index is equal to the number of items, push the item to the back of the list
	if (index == num_items) {
		push_back(item);
		return;
	}

	//Otherwise, traverse the list to find the position to insert the item
	Node<Item_Type>* current_node = head;
	for (size_t i = 0; i < index - 1; i++) {
		current_node = current_node->next;
	}
	current_node->next = new Node<Item_Type>(item, current_node->next);
	num_items++;	//Increment the number of items in the list
};

//Remove an item from a specific position in the list
template <typename Item_Type>
bool SinglyLinkedList<Item_Type>::remove(size_t index) {
	//Check if the index is valid
	if (index >= num_items) {
		std::cerr << "Error: Index out of bounds" << std::endl;
		return false;
	}

	//If the index is 0, pop the item at the front of the list
	if (index == 0) {
		pop_front();
		return true;
	}

	//If the index is equal to the number of items - 1, pop the item at the back of the list
	if (index == num_items - 1) {
		pop_back();
		return true;
	}

	//Otherwise, traverse the list to find the item to remove
	Node<Item_Type>* current_node = head;
	for (size_t i = 0; i < index - 1; i++) {
		current_node = current_node->next;
	}
	Node<Item_Type>* temp = current_node->next;
	current_node->next = current_node->next->next;
	delete temp;
	num_items--;	//Decrement the number of items in the list
	return true;
};

//Find the index of a specific item in the list
template <typename Item_Type>
size_t SinglyLinkedList<Item_Type>::find(const Item_Type& item) {
	//Check if the list is empty
	if (empty()) {
		std::cerr << "Error: Index out of bounds" << std::endl;
		return num_items;
	}

	//Check if the item is the first entry
	if (item == front()) {
		return 0;
	}

	//Check if the item is the last entry
	if (item == back()) {
		return num_items - 1;
	}

	//Traverse the list to find the item
	Node<Item_Type>* current_node = head;
	for (size_t i = 0; i < num_items; i++) {
		if (current_node->data == item) {
			return i;
		}
		current_node = current_node->next;
	}

	//If the item is not found, return num_items
	return num_items;
};

//Explicit template instantiation for int type
template class SinglyLinkedList<int>;