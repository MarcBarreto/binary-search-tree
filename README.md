# Binary Search Tree

## Table of Contents
1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Installation](#installation)
4. [Usage](#usage)
5. [BinarySearchTree Class](#binarysearchtree-class)
6. [Menu Options](#menu-options)
7. [License](#license)

## Introduction
This project implements a Binary Search Tree (BST) in C++. The `BinarySearchTree` class includes methods for inserting, deleting, searching, and printing nodes. The project also features a menu-driven interface for interacting with the BST.

## Project Structure
The project is organized as follows:
```sh
binary-search-tree
┣ 📜 main.cpp
┣ 📜 data.txt
┗ 📜 README.md
┗ 📜 LICENSE
```


## Installation
To compile and run this project, follow these steps:

1. **Clone the Repository**:
   ```bash
     git clone https://github.com/yourusername/binary-search-tree.git
     cd binary-search-tree
   ```

2. **Compile the Code**:
  ```bash
  g++ main.cpp -o bst
  ```

3. **Run the Executable**:
  ```bash
  ./bst
  ```
## Usage
Upon running the executable, a menu will be displayed with the following options:
  - Load
  - Print
  - Delete
  - Search
  - Exit

The `data.txt` file contains numbers that can be loaded into the BST using the "Load" option in the menu.

## BinarySearchTree Class
The `BinarySearchTree` class includes the following methods:

- insert(int value): Inserts a node with the specified value into the tree.
- deleteNode(int value): Deletes the node with the specified value from the tree.
- search(int value): Searches for a node with the specified value in the tree.
- print(): Prints the tree structure in the terminal.

## Menu Options
The menu provides an interface to interact with the BST:

- Load: Loads numbers from data.txt into the tree.
- Print: Displays the current tree structure in the terminal.
- Delete: Deletes a node with a specified value from the tree.
- Search: Searches for a node with a specified value in the tree.
- Exit: Exits the menu.

## License
This project is licensed under the MIT License. See the LICENSE file for more information.

---

Feel free to explore and modify the code to suit your needs!
