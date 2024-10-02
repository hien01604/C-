// 22520422
// Phạm Thị Minh Hiền
// in class 1
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef Node *node;

// 1. Initialize the stack
node initializeStack()
{
    return nullptr;
}

// 2. Check if the stack is empty
bool isEmpty(node top)
{
    return top == nullptr;
}

// 3. Check if the stack is full (Not applicable for dynamic memory allocation)
bool isFull()
{
    return false;
}

// 4. Push an element onto the stack
void push(node &top, int value)
{
    node newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// 5. Pop an element from the stack
int pop(node &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    node tmp = top;
    int value = tmp->data;
    top = top->next;
    delete tmp;
    return value;
}

// 6. Print the TOP element of the stack
void printTop(node top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Top of the stack: " << top->data << endl;
    }
}

// Main function
int main()
{
    int choice, value;
    node top = initializeStack(); // Initialize the stack

    do
    {
        cout << "==== Menu ====" << endl;
        cout << "1. Initialize the stack." << endl;
        cout << "2. Check if the stack is empty." << endl;
        cout << "3. Check if the stack is full." << endl;
        cout << "4. Push an element onto the stack." << endl;
        cout << "5. Pop an element from the stack." << endl;
        cout << "6. Print the TOP element of the stack." << endl;
        cout << "7. Exit" << endl;

        cout << "Choose option 1-6!" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            top = initializeStack();
            cout << "Stack initialized." << endl;
            break;

        case 2:
            if (isEmpty(top))
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is not empty." << endl;
            }
            break;

        case 3:
            if (isFull())
            {
                cout << "Stack is full." << endl;
            }
            else
            {
                cout << "Stack is not full." << endl;
            }
            break;

        case 4:
            cout << "Enter value to push: ";
            cin >> value;
            push(top, value);
            break;

        case 5:
            value = pop(top);
            if (value != -1)
            {
                cout << "Popped element: " << value << endl;
            }
            break;

        case 6:
            printTop(top);
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
