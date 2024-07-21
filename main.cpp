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

    // Private method to delete node
    Node* search(Node* node, int value) {
        // Checks if Node is null or Value was found
        if (!node || node->value == value) return node;

        // Checks if Value is to the right or left of the Node
        if (value < node->value)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Private method to delete node
    Node* deleteNode(Node* node, int value) {
        // Checks if Node is null
        if (!node) return node;

        // Checks if Value is greater or less than Node Value
        if (value < node->value)
            node->left = deleteNode(node->left, value);
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        else {
            // Search Node to delete
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Replace Node Value for less value to the right
            Node* temp = minValueNode(node->right);
            node->value = temp->value;

            // Delete less Node to the right
            node->right = deleteNode(node->right, temp->value);
        }

        return node;
    }

    // Private Method to Search Node to the left
    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left)
            current = current->left;
        return current;
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Public Method to Insert Value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public Method To Show Tree
    void print() {
        print(root, 0);
    }

    // Method Public to Search Value in the Tree
    bool search(int value) {
        return search(root, value) != nullptr;
    }

    // Public Method to Delete Value
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }
};

int main() {


    return 0;
}