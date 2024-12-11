#include <iostream>
using namespace std;

// Create an empty doubly linked list
// Create a node with specified data
// Insert a node to doubly linked list
//                At the front
//                After a given node
//                At the end
//                Before a given node
// Delete a node from doubly linked list
//                  At the front
//                  At the end
//                  After a given node
//                  Before a given node
//                  At given a position
//                  With specified data x
//                  All node with specified data x
// Reverse a Doubly Linked List
// Find a node in doubly linked list

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
typedef Node *node;

// Create a node with specified data
node createNode(int x)
{
    node newNode = new Node();
    newNode->data = x;
    node prev = nullptr;
    node next = nullptr;
    return newNode;
}

// Insert at the beginning
void insertFront(node &head, int x)
{
    node newNode = createNode(x);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert a node at the end
void insertAtTheEnd(node &head, int x)
{
    node newNode = createNode(x);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    node tmp = head;
    while (head->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

// Insert after a given position
void insertAfterPos(node &head, int x, int pos)
{
    node newNode = createNode(x);
    node tmp = head;

    while(pos > 1 && tmp != nullptr){
        tmp = tmp->next;
        pos--;
    }
    if(tmp->next == nullptr){
        tmp->next = newNode;
        newNode->prev = tmp;
        newNode->next = nullptr;
    }
    else{
        node tmp2 = tmp->next;
        tmp->next = newNode;
        tmp2->prev = newNode;
        newNode->prev = tmp;
        newNode->next = tmp2;
    }
}

// Insert before given position
void insertBeforePos(node&head, int x, int pos){
    node newNode = createNode(x);
    node tmp = head;

    while(pos > 2){
        tmp = tmp->next;
        pos--;
    }
    if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else{
        node tmp2 = tmp->next;
        tmp->next = newNode;
        tmp2->prev = newNode;
        newNode->next = tmp2;
        newNode->prev = tmp;    
    }
}
// Delete At the front
void deleteFront(node& head){
    if(head == nullptr){
        cout <<"Empty list.";
        return;
    }
    node tmp = head;
    head = head->next;
    if(head != nullptr){
        head->prev = nullptr;
    }
    delete tmp;
}

// Delete At the end
void deleteEnd(node &head){
    if(head == nullptr){
        cout << "Empty list.";
        return;
    }
    if(head->next == nullptr){
        deleteFront(head);
        return;
    }
    node tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    node tmp2 = tmp->prev;
    tmp2->next = nullptr;
    delete tmp;
}
// Delete After a given node
// Delete Before a given node
// Delete At given a position
void deleteAtPos(node &head, int pos){
    node tmp = head;
    if(pos == 1){
        deleteFront;
    }
    while(pos > 1){
        tmp = tmp->next;
        pos--;
    }
    if(tmp->next ==nullptr){
        deleteEnd;
    }
    else{
        node tmp2 = tmp->prev;
        tmp2->next = tmp->next;
        tmp->next->prev = tmp2;
        delete tmp;
    }
}
// Delete With specified data x
void deleteX(node &head, int x){
    if(head == nullptr){
        return;
    }
    node tmp = head;
    while(tmp->next != nullptr && tmp->data != x){
        tmp = tmp-> next;
    }
    if(tmp==nullptr){
        return;
    }
    if(tmp ==head){
        deleteFront;
    }
    if(tmp->next == nullptr){
        deleteEnd;
    }
    node tmp2 = tmp->prev;
    tmp2->next = tmp->next;
    tmp->next->prev = tmp2;
}
// Delete All node with specified data x
void deleteAllX(node &head, int x){
    if(head == nullptr){
        return;
    }
    node tmp = head; 
    while(tmp->next != nullptr){
        if(tmp->data == x){
            node toDelete = tmp;
            if(tmp == head){
                head = head->next;  
                if(head != nullptr){
                    head->prev == nullptr;
                }  
            }else if(tmp->next == nullptr){
                tmp->prev->next=nullptr;
            }
            else{
                node tmp2 = tmp->prev;
                tmp2->next = tmp->next;
                tmp->next->prev = tmp2;
            }
        }
    }
}

