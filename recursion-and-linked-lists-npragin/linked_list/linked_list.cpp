#include "linked_list.hpp"
#include <iostream>

linked_list::linked_list(const linked_list& other) {
	clear();
	if (!other.head) {
		return;
	}
	length = other.length;
	head = new node;
	head->val = other.head->val;
	node* itr = head;
	node* otherItr = other.head;
	while (otherItr->next) {
		otherItr = otherItr->next;
		node* newNode = new node;
		newNode->val = otherItr->val;
		itr->next = newNode;
		itr = itr->next;
	}
}

void linked_list::operator=(const linked_list& other) {
	clear();
	if (!other.head) {
		return;
	}
	length = other.length;
	head = new node;
	head->val = other.head->val;
	node* itr = head;
	node* otherItr = other.head;
	while (otherItr->next) {
		otherItr = otherItr->next;
		node* newNode = new node;
		newNode->val = otherItr->val;
		itr->next = newNode;
		itr = itr->next;
	}
}

linked_list::~linked_list() {
	if (head == nullptr) {
		return;
	}
	
	node* lag = head;
	head = head->next;

	while (head) {
		delete lag;
		lag = head;
		head = head->next;
	}
	delete lag;
}

int linked_list::get_length() { return length; }

void linked_list::print() {
	node* itr = head;
	while (itr) {
		std::cout << std::to_string(itr->val) + " ";
		itr = itr->next;
	}
	std::cout << std::endl;
}

void linked_list::clear() {
	if (length == 1) {
		length = 0;
		delete head;
		head = nullptr;
		return;
	}

	length = 0;
	node* lag = head;
	head = head->next;
	
	while (head) {
		delete lag;
		lag = head;
		head = head->next;
	}

	delete lag;
}

void linked_list::push_front(int value) {
	node* newHead = new node;
	newHead->val = value;
	newHead->next = head;
	head = newHead;

	length++;
}

void linked_list::push_back(int value) {
	if (length == 0) {
		push_front(value);
		return;
	}
	length++;
	node* itr = head;
	while (itr->next) {
		itr = itr->next;
	}

	node* newTail = new node;
	newTail->val = value;
	itr->next = newTail;
}

void linked_list::insert(int value, int index) {
	if (index > length)
		return;
	if (index == 0) {
		push_front(value);
		return;
	}

	node* newNode = new node;
	newNode->val = value;
	node* itr = head;

	for (int i = 0; i < index - 1; i++) {
		itr = itr->next;
	}

	newNode->next = itr->next;
	itr->next = newNode;

	length++;
}

void linked_list::pop_front() {
	if (length == 0)
		return;

	node* temp = head;
	head = head->next;
	delete temp;
	length--;
}

void linked_list::pop_back() {
	if (length == 0)
		return;
	if (length == 1) {
		delete head;
		head = nullptr;
		length = 0;
		return;
	}

	node* lag = head;
	node* lead = lag->next;

	while (lead->next) {
		lag = lead;
		lead = lead->next;
	}

	lag->next = nullptr;
	delete lead;
	length--;
}

void linked_list::remove(int index) {
	if (index >= length)
		return;
	if (index == 0) {
		pop_front();
		return;
	}
	if (index == length - 1) {
		pop_back();
		return;
	}

	node* lag = head;
	node* lead = head->next;

	for (int i = 0; i < index - 1; i++) {
		lag = lead;
		lead = lead->next;
	}

	lag->next = lead->next;
	delete lead;
	length--;
}

void linked_list::sort_ascending() {
	head = merge_sort(head, true);
}

void linked_list::sort_descending() {
	head = merge_sort(head, false);
}

node* linked_list::merge_sort(node* head, bool ascending) {
	if (!head || !head->next) {
		return head;
	}

	node* left = head;
	node* middle = split(head);
	node* right = middle->next;
	middle->next = nullptr; //Splits the list

	left = merge_sort(left, ascending);
	right = merge_sort(right, ascending);
	return merge(left, right, ascending);
}

node* linked_list::split(node* head) {
	node* lag = head;
	node* lead = lag->next;

	while (lead && lead->next) {
		lead = lead->next;
		if (lead && lead->next) {
			lead = lead->next;
			lag = lag->next;
		}
	}

	return lag;
}

node* linked_list::merge(node* left, node* right, bool ascending) {
	node* dummyHead = new node;
	node* itr = dummyHead;

	while (left && right) {
		if (ascending ? left->val <= right->val : left->val >= right->val) {
			itr->next = left;
			left = left->next;
		} else {
			itr->next = right;
			right = right->next;
		}
		itr = itr->next;
	}

	while (left) {
		itr->next = left;
		left = left->next;
		itr = itr->next;
	}

	while (right) {
		itr->next = right;
		right = right->next;
		itr = itr->next;
	}

	itr = dummyHead->next;
	delete dummyHead;
	return itr;
}