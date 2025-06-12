# Coffee++ Shop

A C++ program that simulates a coffee shop management system. The program allows users to manage coffee orders, track inventory, and handle customer transactions.

## Features

- View shop information (menu, address, phone, total revenue) and order history
- Add/remove coffee items from menu and search by name or price range
- Place and manage coffee orders
- Track shop revenue and sales across all transactions
- Automatic file I/O for persistent data storage

## Technical Requirements
- Implements Big 3 for dynamic memory management
  - Verifiable by running `make test`
- No STL usage allowed
- Memory leak free (valgrind tested)
- Graceful error handling for file operations

## Building and Running

1. Compile the program:
```bash
make
```

2. Run the executable:
```bash
./start_shop
```

## File Structure

- `prog.cpp` - Main program entry point
- `shop.h/cpp` - Shop management functionality
- `menu.h/cpp` - Menu and item management
- `order.h/cpp` - Order processing
- `coffee.h/cpp` - Coffee item definitions
- `display.h/cpp` - User interface and display functions

## Input Files

- `menu.txt` - Contains coffee menu items and prices
- `shop_info.txt` - Shop configuration
- `orders.txt` - Order history

## Requirements

- C++11
- Make
