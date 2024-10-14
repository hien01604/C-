/*
MSSV: 22520422
Phạm Thị Minh Hiền 
Lab_2 Homework question 1
*/

#include <iostream>
using namespace std;

// Node structure for the stack
struct Node {
    int data;       // Disk size
    Node* next;     // Pointer to the next node
};

// Custom Stack class
class Stack {
private:
    Node* topNode;  // Pointer to the top node of the stack

public:
    // Constructor to initialize the stack
    Stack() : topNode(nullptr) {}

    // Push a disk onto the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop a disk from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop." << endl;
            return -1; // Indicates an error
        }
        Node* temp = topNode;
        int poppedValue = temp->data;
        topNode = topNode->next;
        delete temp;
        return poppedValue;
    }

    // Peek at the top disk without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty, cannot peek." << endl;
            return -1; // Indicates an error
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Print the contents of the stack (used to display the tower status)
    void printStack() const {
        Node* current = topNode;
        cout << "STACK = < ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << ">" << endl;
    }

    // Destructor to clean up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Function to move a disk from one tower to another
void moveDisk(Stack &fromTower, Stack &toTower, char from, char to) {
    int disk = fromTower.pop();
    toTower.push(disk);
    cout << from << " -> " << to << endl;
}

// Function to print the current state of all three towers
void printTowers(Stack &A, Stack &B, Stack &C) {
    cout << "A Tower" << endl;
    A.printStack();
    cout << "------------------------------" << endl;

    cout << "B Tower" << endl;
    B.printStack();
    cout << "------------------------------" << endl;

    cout << "C Tower" << endl;
    C.printStack();
    cout << "------------------------------" << endl;
}

// Recursive Tower of Hanoi function
void towerOfHanoi(int n, Stack &source, Stack &destination, Stack &auxiliary, char from, char to, char aux, Stack &A, Stack &B, Stack &C) {
    if (n == 1) {
        moveDisk(source, destination, from, to);
        printTowers(A, B, C); // Print tower status after each move
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination, from, aux, to, A, B, C);
    moveDisk(source, destination, from, to);
    printTowers(A, B, C); // Print tower status after each move
    towerOfHanoi(n - 1, auxiliary, destination, source, aux, to, from, A, B, C);
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    // Initialize the three towers
    Stack A, B, C;

    // Initialize the source tower (A) with disks (largest at the bottom)
    for (int i = n; i >= 1; --i) {
        A.push(i);
    }

    // Display initial tower state
    cout << "======== Demo Stack ========" << endl;
    cout << "0. Creating Tower." << endl;
    printTowers(A, B, C);

    // Call the Tower of Hanoi function
    towerOfHanoi(n, A, C, B, 'A', 'C', 'B', A, B, C);

    return 0;
}
