#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node.hpp"

class linked_list {
private:
	int length = 0;			// the number of nodes contained in the list.
	node* head = nullptr;	// a pointer to the first node in the list.
public:
	// Empty default constructor
	linked_list() = default;

	// Copy constructor
	linked_list(const linked_list& other);

	// Assignment operator overload
	void operator=(const linked_list& other);

	// Destructor
	~linked_list();

	/*********************************************************************
	 ** Function: get_length()
	 ** Description: Returns length of list.
	 ** Returns (int): Length of list (# of nodes).
	 ********************************************************************/
	int get_length();

	/*********************************************************************
	 ** Function: print()
	 ** Description: Prints all values in the list.
	 ********************************************************************/
	void print();

	/*********************************************************************
	 ** Function: clear()
	 ** Description: Removes all nodes from list (and deletes them from the
	 ** 	heap).
	 ** Post-Conditions: length = 0, head = nullptr.
	 ********************************************************************/
	void clear();

	/*********************************************************************
	 ** Function: push_front()
	 ** Description: Inserts a new value at the front (beginning) of the list
	 		in a new node.
	 ** Parameters: int - value being added to list.
	 ********************************************************************/
	void push_front(int value);

	/*********************************************************************
	 ** Function: push_back()
	 ** Description: Insert a new value at the back (end) of the list in a
	 		new node.
	 ** Parameters: int - value being added to list.
	 ********************************************************************/
	void push_back(int value);

	/*********************************************************************
	 ** Function: insert()
	 ** Description: insert a new value at a specified index.
	 ** Parameters: int index - index of where element is being added.
	 				int value - value being added to list.
	 ** Post-Conditions: given value inserted at given index in a new node, and
	 		all subsequent elements shifted over to make room for it. Length
			should be one greater than before.
	 ********************************************************************/
	void insert(int value, int index);

	/*********************************************************************
	 ** Function: pop_front()
	 ** Description: Remove node at the front (beginning) of the list.
	 ** Post-Conditions: Node at the front of the list is removed from the
	 		list and deleted from the heap
	 ********************************************************************/
	void pop_front();

	/*********************************************************************
	 ** Function: pop_back()
	 ** Description: Remove node at the back (end) of the list.
	 ** Post-Conditions: Node at the back of the list is removed from the
	 		list and deleted from the heap
	 ********************************************************************/
	void pop_back();

	/*********************************************************************
	 ** Function: remove()
	 ** Description: Remove node at the given index.
	 ** Parameters: int - index of where node is being removed.
	 ** Post-Conditions: Node at given index is removed. Subsequent nodes
	 		are shifted over to accommodate. Length of list should be one
			less than before.
	 ********************************************************************/
	void remove(int index);

	/*********************************************************************
	 ** Function: sort_ascending()
	 ** Description: Sorts list in ascending order.
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		ascending order of their respective values.
	 ********************************************************************/
	void sort_ascending();

	/*********************************************************************
	 ** Function: sort_descending()
	 ** Description: Sorts list in descending order.
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		descending order of their respective values.
	 ********************************************************************/
	void sort_descending();

   /* Name: merge_sort
    * Description: Recursively sorts linked list in either order
	* Parameters:
	*     head (node*): Head of the linked list to be sorted
	*     ascending (bool): ascending (true) or descending (false) order
	* Returns (node*): Pointer to head of the sorted list
    */
	node* merge_sort(node* head, bool ascending);

   /* Name: split
    * Description: Returns a pointer to the middle node of a linked list
	* Parameters:
	*     head (node*): Head of the linked list to split
	* Returns (node*): Pointer to middle of the linked list
    */
	node* split(node* head);

   /* Name: merge
    * Description: Merges two linked lists in either order
	* Parameters:
	*     left (node*): Head of one linked list to be merged
	*     right (node*): Head of another linked list to be merged
	*     ascending (bool): ascending (true) or descending (false) order
	* Returns (node*): Pointer to head of the sorted list
    */
	node* merge(node* left, node* right, bool ascending);

};

#endif
