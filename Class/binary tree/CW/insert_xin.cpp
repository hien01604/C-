#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <random>
#include <iomanip>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to create a random tree with a user-defined number of levels
Node* createRandomTree(int maxLevels) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> childDis(0, 1); // For deciding children

    // Create root with value 1
    Node* root = new Node(1);
    queue<pair<Node*, int>> q; // {node, depth}
    q.push({root, 1});
    int nodeValue = 2; // Start numbering from 2

    while (!q.empty()) {
        auto [current, depth] = q.front();
        q.pop();

        if (depth >= maxLevels)
            continue; // Skip if at max depth

        // Randomly decide to add children
        bool addLeft = childDis(gen);
        bool addRight = childDis(gen);

        // Add left child if allowed
        if (addLeft) {
            current->left = new Node(nodeValue++);
            q.push({current->left, depth + 1});
        }

        // Add right child if allowed
        if (addRight && nodeValue <= pow(2, maxLevels) - 1) {
            current->right = new Node(nodeValue++);
            q.push({current->right, depth + 1});
        }
    }

    return root;
}

// Function to print the tree visually
void printTree(Node* root) {
    if (!root) return;

    int height = 4; // Maximum height to display (fixed for consistent representation)
    vector<vector<string>> levels(height);

    // BFS to collect nodes at each level
    queue<pair<Node*, pair<int, char>>> q; // Node, {level, L/R indicator}
    q.push({root, {0, 'R'}});               // Root is marked as 'R' by default

    while (!q.empty()) {
        auto [node, info] = q.front();
        auto [level, indicator] = info;
        q.pop();

        if (level >= height) continue;

        // Add node value or "[]" for null nodes
        string nodeStr = node ? to_string(node->value) : "[]";
        if (node && (indicator != 'R' || level != 0)) {
            nodeStr += "(" + string(1, indicator) + ")";
        }
        levels[level].push_back(nodeStr);

        // Add children or null placeholders for spacing
        if (level < height - 1) {
            if (node) {
                q.push({node->left, {level + 1, 'L'}});
                q.push({node->right, {level + 1, 'R'}});
            } else {
                q.push({nullptr, {level + 1, 'L'}});
                q.push({nullptr, {level + 1, 'R'}});
            }
        }
    }

    // Print each level with proper spacing
    int maxWidth = pow(2, height - 1) * 6;
    for (int i = 0; i < height; i++) {
        int nodeSpacing = maxWidth / pow(2, i);
        int padding = nodeSpacing / 2;

        cout << string(padding, ' ');

        for (const string& value : levels[i]) {
            cout << setw(4) << value;
            cout << string(nodeSpacing - 4, ' ');
        }
        cout << endl;
    }
}

// Function to find the first missing node using BFS
pair<Node*, bool> findFirstMissingNode(Node* root) {
    if (!root) return {nullptr, false};

    queue<pair<Node*, int>> q; // Node and its depth
    q.push({root, 1});

    while (!q.empty()) {
        auto [current, depth] = q.front();
        q.pop();

        // Check if current node is missing a child
        if (current->left && !current->right) {
            return {current, false}; // needs right child
        }
        if (!current->left && current->right) {
            return {current, true}; // needs left child
        }

        if (current->left)
            q.push({current->left, depth + 1});
        if (current->right)
            q.push({current->right, depth + 1});
    }

    return {nullptr, false};
}

int main() {
    int levels;
    cout << "Enter the number of levels for the tree: ";
    cin >> levels;

    Node* root = createRandomTree(levels);

    cout << "\nRandom Tree Structure:\n";
    printTree(root);

    int userValue = 0;
    while (userValue != -1) {
        cout << "\nEnter a value to insert (Type -1 to exit): ";
        cin >> userValue;

        auto [missingNode, isLeft] = findFirstMissingNode(root);

        if (missingNode) {
            if (isLeft) {
                missingNode->left = new Node(userValue);
            } else {
                missingNode->right = new Node(userValue);
            }

            cout << "\nTree after insertion:\n";
            printTree(root);
        } else {
            cout << "\nNo missing positions found in the tree.\n";
        }
    }

    return 0;
}
