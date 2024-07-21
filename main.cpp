// Library for Input and Output Operations
#include <iostream>

// Library for File Operations
#include <fstream>

// Library for String Operations
#include <cstring>

// Library to manipulate String in I/O Operations
#include <sstream>

using namespace std;

class BinarySearchTree {

private:
    struct Node {
        int value; // Node Value
        Node *left; // Left Node
        Node *right; // Right Node
        
        // Node Construct
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root; // Root Node

    // Private method to insert a value in the tree
    Node* insert(Node* node, int value) {

        // Checks if Node is null
        if (!node) return new Node(value);

        // Checks if Value is to insert to the left or right
        if (value < node->value)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Private method to show the tree 
    void print(Node* node, int space) {
        // Checks if node is null
        if (!node) return;

        // Increases space for formatting
        space += 10;

        // Print Right Node
        print(node->right, space);  
        cout << endl;

        for (int i = 10; i < space; i++) cout << " ";

        // Print Node value
        cout << node->value << "\n";

        // Print Left Node
        print(node->left, space);
    }

    Node* search(Node* node, int value) {
        // Checks if Node is null or Value was found
        if (!node || node->value == value) return node;

        // Checks if Value is to the right or left of the Node
        if (value < node->value)
            return search(node->left, value);
        else
            return search(node->right, value);
    }
};

int main() {


    return 0;
}