# Warehouse Inventory System

This repository contains a **Warehouse Inventory System** implemented in C++. The program uses a linked list to manage inventory items and offers a menu-driven interface for common operations such as adding, removing, searching, updating, and displaying items.

## Overview

The Warehouse Inventory System demonstrates the following key concepts:

- **Linked List Data Structure:**  
  Each inventory item is represented by a node in a linked list. Each node contains:
  - **ID:** A unique identifier for the item.
  - **Name:** The name of the item.
  - **Quantity:** The current quantity of the item.
  - **Next Pointer:** Points to the next node in the list.

- **Menu-Driven Interface:**  
  The `main()` function presents a menu that allows the user to choose from various operations:
  1. **Add a New Item:** Inserts a new node into the linked list.
  2. **Remove an Item:** Deletes a node based on its ID.
  3. **Search for an Item by ID:** Traverses the list to find an item with a matching ID and displays its details.
  4. **Update Item Quantity:** Updates the quantity of an existing item.
  5. **Display Warehouse Information:** Prints all items in the inventory in a formatted table.
  6. **Exit the Program:** Terminates the application.

- **ANSI Escape Codes for Styling:**  
  The program uses ANSI escape codes to color the output, making error messages and informational texts more visually distinctive.


## Key Functions

- **`displayInfo(Node*& head)`**  
  Displays all inventory items in a formatted table. If no items are present, it prints an error message.

- **`alreadyPresent(Node*& head, long id)`**  
  Checks whether an item with a given ID already exists in the list.

- **`insertItem(long id, string name, int quantity, Node*& head, Node*& tail)`**  
  Inserts a new item into the inventory. If the list is empty, the new item becomes both the head and the tail.

- **`searchById(long id, Node*& head)`**  
  Searches for an item by its ID and displays its details if found.

- **`updateQuantity(long id, int quantity, Node*& head)`**  
  Updates the quantity of an item with the specified ID.

- **`removeItem(long id, Node*& head)`**  
  Removes an item from the inventory based on its ID.

- **`isEmpty(Node*& head)`**  
  Checks if the inventory is empty.

- **Main Loop (in `main()`):**  
  Provides a user interface to perform the above operations based on user input.


## Compilation

To compile the code, use a C++ compiler such as `g++`. For example:

```bash
g++ -o inventory WarehouseInventorySystem.cpp
```

## Execution

After successful compilation, run the executable from your terminal:
```bash
./inventory
```

## Contact
For any questions or feedback, please contact me at:
<br>
Email: workforxynax@gmail.com

Thank you for checking out my Warehouse Inventory Management System repository. I hope you find the code and documentation both useful and informative. Happy Coding! 😊

sync update