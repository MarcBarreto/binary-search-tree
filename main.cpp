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

    Node* root;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }
};

int main() {


    return 0;
}