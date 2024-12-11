#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
};

void createList(List& L) {
    L.pHead = L.pTail = nullptr;
}

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->pNext = nullptr;
    return p;
}

void addHead(List& L, Node* p) {
    if (!L.pHead) {
        L.pHead = L.pTail = p;
    }
    else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void addTail(List& L, Node* p) {
    if (!L.pHead) {
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

int removeHead(List& L) {
    if (!L.pHead) return -1;
    Node* p = L.pHead;
    int data = p->data;
    L.pHead = L.pHead->pNext;
    delete p;
    if (!L.pHead) L.pTail = nullptr;
    return data;
}

void inputList(List& L) {
    createList(L);
    int x;
    cout << "Enter elements of the list (enter 0 to stop): ";
    while (true) {
        cin >> x;
        if (x == 0) break;
        addTail(L, createNode(x));
    }
}

void printList(const List& L) {
    Node* p = L.pHead;
    while (p) {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl;
}

void partitionList(List& A, List& A1, List& A2, int pivot) {
    while (A.pHead) {
        int t = removeHead(A);
        if (t < pivot) addTail(A1, createNode(t));
        else if (t > pivot) addTail(A2, createNode(t));
    }
}

void quickSort(List& A) {
    if (!A.pHead || !A.pHead->pNext) return;

    cout << "Current List: ";
    printList(A);

    List A1, A2;
    createList(A1);
    createList(A2);

    // Chọn pivot là phần tử đầu tiên
    int pivot = removeHead(A);
    Node* pivotNode = createNode(pivot);

    partitionList(A, A1, A2, pivot);
    cout << "Pivot: " << pivot << endl;
    cout << "List A1 (less than pivot): ";
    printList(A1);
    
    cout << "List A2 (greater than pivot): ";
    printList(A2);

    quickSort(A1);
    quickSort(A2);

    // Gộp danh sách theo thứ tự, tránh lặp pivot
    if (A1.pHead) {
        A = A1;
        A1.pTail->pNext = pivotNode;
    }
    else {
        A.pHead = A.pTail = pivotNode;
    }

    pivotNode->pNext = A2.pHead;
    if (A2.pTail) {
        A.pTail = A2.pTail;
    }
    else {
        A.pTail = pivotNode;
    }

    cout << "Merged and Sorted List: ";
    printList(A);
    cout << "--------------" << endl;
}

int main() {
    List A;
    inputList(A);
    cout << "Original List: ";
    printList(A);
    quickSort(A);
    cout << "Final Sorted List: ";
    printList(A);
    return 0;
}
