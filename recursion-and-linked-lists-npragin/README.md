# Recursion and Linked Lists Assignment

This assignment consists of two main components: implementing recursive algorithms and creating a linked list data structure.

## Components

### 1. Recursion
- Problem: Given a number of stairs, calculate the number of ways to climb the stairs using either 1, 2, or 3 steps at a time.
- Implementation of recursive algorithms in `stairs.cpp`

### 2. Linked List
- Implementation of a linked list data structure in `linked_list.cpp`
- Custom node implementation in `node.hpp`

## Implementation Details

### Linked List Features
- Custom implementation of a linked list data structure
- In-place merge sort implementation for both ascending and descending order
  - Same algorithm used for both sort orders, with a boolean parameter to determine direction
- insert, remove, push_front, push_back, pop_front, pop_back, clear, print, and get_length methods

## Building and Testing
Each component can be built and tested independently:
1. Navigate to either the `recursion` or `linked_list` directory
2. Run `make` to build the project
3. Run `./test` to execute the tests
