// 22520422
// Phạm Thị Minh Hiền
// Classwork - 02

#include <iostream>
using namespace std;

// Node structure for the queue
struct Node
{
    int data;
    Node *next;
};

// Queue structure
struct Queue
{
    Node *front, *rear;
};

// 1. Function to initialize the queue
Queue *initializeQueue()
{
    Queue *q = new Queue();
    q->front = q->rear = nullptr;
    return q;
}

// 2. Function to check if the queue is empty
bool isEmpty(Queue *q)
{
    return (q->front == nullptr);
}

// 3. Function to check if the queue is full (not applicable in dynamic linked list)
bool isFull()
{
    return false;
}

// 4. Function to enqueue an element into the queue
void enqueue(Queue *q, int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = nullptr;

    // If the queue is empty, both front and rear will point to the new node
    if (q->rear == nullptr)
    {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of the queue and update rear
    q->rear->next = temp;
    q->rear = temp;
}

// 5. Function to dequeue an element from the queue
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty, cannot dequeue." << endl;
        return -1;
    }

    // Store the front node and move the front pointer to the next node
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    // If the front becomes nullptr, then make rear nullptr as well
    if (q->front == nullptr)
    {
        q->rear = nullptr;
    }

    delete temp;
    return data;
}

// 6. Print the REAR and FRONT elements of the queue
void printFrontRear(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Front element: " << q->front->data << endl;
        cout << "Rear element: " << q->rear->data << endl;
    }
}

// Input queue
void inputQueue(Queue *q)
{
    int n, value;
    cout << "Enter the number of elements to the queue: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        enqueue(q, value);
    }
}
void outputQueue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node *temp = q->front;
    cout << "Queue elements: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function with a menu to display choices
int main()
{
    Queue *q = initializeQueue();
    int choice, value;
    inputQueue(q);
    outputQueue(q);
    do
    {
        cout << "\n==== Queue Menu ====" << endl;
        cout << "1. Initialize the queue" << endl;
        cout << "2. Check if the queue is empty" << endl;
        cout << "3. Check if the queue is full" << endl;
        cout << "4. Enqueue an element" << endl;
        cout << "5. Dequeue an element" << endl;
        cout << "6. Print the REAR and FRONT elements" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q = initializeQueue();
            cout << "Queue initialized." << endl;
            break;

        case 2:
            if (isEmpty(q))
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;

        case 3:
            if (isFull())
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                cout << "Queue is not full." << endl;
            }
            break;

        case 4:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(q, value);
            cout << value << " enqueued to queue." << endl;
            outputQueue(q);

            break;

        case 5:
            value = dequeue(q);
            if (value != -1)
            {
                cout << value << " dequeued from queue." << endl;
            }
            outputQueue(q);
            break;

        case 6:
            printFrontRear(q);
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
