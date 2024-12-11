#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node with given data
Node* CreateNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert a new node into the tree in level-order
Node* InsertNode(Node* root, int data) {
    if (root == NULL) {
        return CreateNode(data);
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        else {
            temp->left = CreateNode(data);
            return root;
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
    return root;
}

// Print the tree in level-order, with [] for empty nodes
void PrintTreeByLevel(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    bool hasMoreNodes = true;

    while (hasMoreNodes && !q.empty()) {
        int size = q.size();
        hasMoreNodes = false;

        for (int i = 0; i < size; ++i) {
            Node* temp = q.front();
            q.pop();

            if (temp == nullptr) {
                cout << "[] ";
            }
            else {
                cout << temp->data << " ";
                q.push(temp->left);
                q.push(temp->right);
                if (temp->left || temp->right) {
                    hasMoreNodes = true;
                }
            }
        }
        cout << endl;
    }
}

// Create a random binary tree with a specific number of levels
Node* CreateTreeByLevels(int levels) {
    if (levels <= 0) return nullptr;

    Node* root = CreateNode(rand() % 100); // Root node
    queue<Node*> q;
    q.push(root);

    for (int level = 1; level < levels; ++level) {
        int size = q.size(); // Number of nodes in the current level

        for (int i = 0; i < size; ++i) {
            Node* temp = q.front();
            q.pop();

            // Randomly create left child
            if (rand() % 2) {
                temp->left = CreateNode(rand() % 100);
                q.push(temp->left);
            }

            // Randomly create right child
            if (rand() % 2) {
                temp->right = CreateNode(rand() % 100);
                q.push(temp->right);
            }
        }
    }

    return root;
}

int main() {
    srand(time(0));

    // Input the number of levels for the tree
    cout << "Enter the number of levels: ";
    int levels;
    cin >> levels;

    if (levels <= 0) {
        cout << "Invalid input! Number of levels must be greater than 0." << endl;
        return 1;
    }

    // Create a tree with the specified number of levels
    Node* root = CreateTreeByLevels(levels);

    // Print the initial tree
    cout << "\nInitial tree:" << endl;
    PrintTreeByLevel(root);

    // Input the value of the new node to insert
    cout << "\nEnter the value to insert: ";
    int newValue;
    cin >> newValue;

    // Insert the new node
    root = InsertNode(root, newValue);

    // Print the tree after insertion
    cout << "\nTree after inserting " << newValue << ":" << endl;
    PrintTreeByLevel(root);

    return 0;
}
