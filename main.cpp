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

    // Instance Binary Search Tree Class
    BinarySearchTree bst;

    // Variable that control loop
    bool running = true;

    // Input Buffer
    char input[999];

    while (running) {

        cout << "Select An Option Of The Menu (Type The Letter In Capital Letters)" << endl;
        cout << "(L)oad, (P)rint, (D)elete, (S)earch, (E)xit" << endl;
        cin >> input;

        switch(input[0]) {
            case 'L': {
                cout << "(T)erminal, (F)ile" << endl;
                cin >> input;
                if (input[0] == 'T') {
                    cout << "Enter numbers separated with space. Example: 1 2 3 4 5" << endl;
                    cin.ignore();
                    string line;
                    getline(cin, line);
                    istringstream iss(line);
                    int num;
                    while(iss >> num) bst.insert(num);
                    cout << "Loaded Values!";
                } else if (input[0] == 'F') {
                    cout << "Enter name file" << endl;
                    string filename;
                    cin >> filename;
                    ifstream file(filename);
                    int num;
                    while (file >> num) bst.insert(num);
                    cout << "Loaded File!" << endl;
                }
                break;
            }
            case 'P':
                bst.print();
                break;
            case 'D': {
                cout << "Enter Value To Delete" << endl;
                int delVal;
                cin >> delVal;
                bst.deleteValue(delVal);
                break;
            }
            case 'S': {
                cout << "Enter Value To Search:" << endl;
                int searchVal;
                cin >> searchVal;
                bool found = bst.search(searchVal);
                if (found)
                    cout << "Value Found!" << endl;
                else
                    cout << "Value Not Found!" << endl;
                break;
            }
            case 'E':
                running = false;
                break;
        }
    }

    return 0;

}