#ifndef NODE_HPP
#define NODE_HPP

struct node {
public:
	int val;				// the value that this node stores
	node* next = nullptr;	// a pointer to the next node in the list
};

#endif
