#include <iostream>
using namespace std;

// CreateList: Create empty linked list
// CreateNode: Create a node with data x
// Insertion: Adds an element at the beginning of the list.
//            Adds an element at the end of the list
//            Adds an element before a specified node
//            Adds an element after a specified node
// Deletion: Deletes an element at the beginning of the list.
//           Deletes an element at the end of the list
//           Deletes an element before a specified node
//           Deletes an element after a specified node
//           Delete N-th Node of a Linked List
//           Delete N-th Node from End of a Linked List
//           Deletes a node with specified data x
// Reverse a Linked List
// Move the Last Node to the Front of a Linked List
// Display: Displays the complete list.
// Search: Searches an element using the given key.

struct Node
{
    int data;
    Node *next;
};
typedef Node *node;

// CreateList: Create empty linked list
node createList()
{
    return nullptr;
}

// CreateNode: Create a node with data x
node createNode(int x)
{
    node newNode = new Node; // allocate memory for new node
    newNode->data = x;       // set data x to the new node
    newNode->next = nullptr; // set next pointer to new node
    return newNode;
}

// Insertion: Adds an element at the beginning of the list.
void insertAtBeginning(node &head, int x)
{
    node newNode = createNode(x);
    newNode->next = head;
    head = newNode;
}

// Insertion: Adds an element at the end of the list
void insertAtTheEnd(node &head, int x)
{
    node newNode = createNode(x);
    if (head = nullptr)
    {
        head = newNode;
        return;
    }
    node curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Insertion: Adds an element before a specified node
void insertBeforeKey(node &head, int key, int x)
{
    if (head = nullptr)
    {
        cout << "List is empty.";
        return;
    }
    if (head->data == x)
    {
        insertAtBeginning(head, x);
        return;
    }
    node curr = head;
    while (curr->next != nullptr && curr->next->data != key)
    {
        curr = curr->next;
    }
    if (curr->next == nullptr)
    {
        cout << "Can not find " << key << "in the list.";
    }
    else
    {
        node newNode = createNode(x);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Insertion: Adds an element after a specified node
void insertAfterKey(node &head, int key, int x)
{
    if (head = nullptr)
    {
        cout << "List is empty";
        return;
    }
    node curr = head;
    while (curr->next != nullptr && curr->data != key)
    {
        curr = curr->next;
    }
    if (curr = nullptr)
    {
        cout << "Can not find " << key << "in the list.";
    }
    else
    {
        node newNode = createNode(x);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Deletion: Deletes an element at the beginning of the list.
void deleteAtBeginning(node &head)
{
    if (head == nullptr)
    {
        cout << "List is emty. Can not delete." << endl;
        return;
    }
    node tmp = head;
    head = head->next;
    delete tmp;
}

// Deletion: Deletes an element at the end of the list
void deleteAtTheEnd(node &head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Can not delete." << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    node curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
}
// Deletion: Deletes an element before a specified node
void deleteBeforeKey(node &head, int key)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "The list is emty or the list has 1 element, so can not delete before key." << endl;
        return;
    }
    if (head->next->data == key)
    {
        deleteAtBeginning(head);
        return;
    }
    node curr = head;
    while (curr->next->next != nullptr && curr->next->next->data != key)
    {
        curr = curr->next;
    }
    if (curr->next->next == nullptr)
    {
        cout << "Can not find " << key << "in the list." << endl;
    }
    else
    {
        node tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
    }
}
// Deletion: Deletes an element after a specified node
void deleteAfterKey(node &head, int key)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "List is emty or the list has one element, can not delete key." << endl;
        return;
    }
    node curr = head;
    while (curr != nullptr && curr->data != key)
    {
        curr = curr->next;
    }
    if (curr == nullptr || curr->next == nullptr)
    {
        cout << "No element exists after the key." << endl;
    }
    else
    {
        node tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
    }
}

// Deletion: Delete N-th Node of a Linked List
void deleteNthNode(node &head, int N)
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }
    node tmp = head;
    if (N == 1)
    {
        head = head->next;
        delete tmp;
        return;
    }
    node prev = nullptr;
    node curr = head;
    for (int i = 1; i < N; i++)
    {
        prev = curr;
        curr = curr->next;

        if (curr->next == nullptr)
        {
            cout << "The list has fewer than " << N << "elements" << endl;
            return;
        }
    }
    prev->next = curr->next;
    delete curr;
}
// Deletion: Deletes the N-th node from the end of a linked list
void deleteNthFromEnd(node &head, int N)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Use two pointers: first and second
    node first = head, second = head;

    // Move the first pointer N steps ahead
    for (int i = 0; i < N; ++i)
    {
        if (first == nullptr)
        {
            cout << "The list has fewer than " << N << " elements." << endl;
            return;
        }
        first = first->next;
    }

    // If first becomes nullptr, the N-th node from the end is the head node
    if (first == nullptr)
    {
        node temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Move both pointers until first reaches the end of the list
    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    // Delete the N-th node from the end (second->next)
    node temp = second->next;
    second->next = second->next->next;
    delete temp;
}

// Deletion: Deletes a node with specified data x
void deleteNodeWithData(node &head, int x)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == x)
    {
        node tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    node curr = head;
    node prev = nullptr;
    while (curr->next != nullptr && curr->data != x)
    {
        curr = curr->next;
        prev = curr;
    }
    if (curr == nullptr)
    {
        cout << "Can not find " << x << "in the list." << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

// Reverse a Linked List
void reverse(node&head){
    if(head == nullptr){
        cout << "Empty list." << endl;
        return;
    }
    node prev = nullptr;
    node next =nullptr;
    while(head!=nullptr ){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
}
// Move the Last Node to the Front of a Linked List
void moveLastToFront(node&head){
    if(head == nullptr || head->next == nullptr){
        cout << "List is empty or contains one node." << endl;
        return;
    }
    node prev = nullptr;
    node curr = head;

    while(curr->next != nullptr){
        prev = head;
        head = head->next;
    }
    prev->next = nullptr;
    curr->next = head;
    head = curr;
}

// Display: Displays the complete list.
void display(node head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    node curr = head;
    while (curr != head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Search: Searches an element using the given key.
// return the adress of that Node if found, otherwise return NULL
node findNode(node &head, int x)
{
    node p = head;
    while (p != nullptr)
    {
        if (p->data == x)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
// Search for an element with key x using bool
bool searchElement(node head, int x)
{
    node curr = head;
    while (curr != nullptr)
    {
        if (curr->data == x)
        {
            return true; // Element found
        }
        curr = curr->next;
    }
    return false; // Element not found
}

// 
int deleteNth(List &l, int n){
    if(pHead == nullptr){
        return 0;
    }
    if(n == 1){
        Node* tmp = pHead;
        pHead = pHead->next;
        delete tmp;
        return 1;
    }
    Node* curr = pHead;
    Node* prev = nullptr;
    if(int i = 1; i < N; i++){
        prev = curr;
        curr = curr->next;
        if(curr->next == nullptr){
            return 0;
        }
    }
    prev->next = curr->next;
    delete curr;
}