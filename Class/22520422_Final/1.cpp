//STT: 14 
//Full Name: Pham Thi Minh Hien
//Question 1

#include <iostream>
using namespace std;

struct Node{
    string name;
    string planet;
    string traits;
    Node* next;
    Node* prev;
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
int interpolationSearch(int arr[], int n, int x){
	int i = 1;
	int lo = 0, hi = (n - 1);
	while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
		if (lo == hi){
			if (arr[lo] == x) return lo;
			return -1;
	}
	int pos = lo + (((hi-lo)*(x-arr[lo]))/(arr[hi]-arr[lo]));
		cout<<"Attempt "<<i<<": "<<endl;
		i++;
		cout << "low: " << lo<< ", high: " << hi << ", pos: " << pos << ", arr[pos]: " << arr[pos] << endl;
		if (arr[pos] == x) return pos;
		if (arr[pos] < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return -1;
}

/* Using the doubly linked list from previous, implement a Quick Sort algorithm to sort the
zodiac signs based on their starting dates in ascending order. Return the sorted linked list.
Ensure that your sorting algorithm maintains stability when two signs have overlapping date
ranges*/
// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // chọn pivot là số cuối cùng
    int i = low - 1;
    for (int j = low; j < high; j++) { // những số lớn hơn pivot thì đổi chỗ với những số lớn hơn pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // đem pivot vô giữa chia đôi ra
    return i + 1;
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
// insert a new zodiac sign to BST 
Node* InsertNode(Node*root, int data)
if(root == null){
    return CreateNode(data);
}
queue<Node*> q;
q.push(root);
while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    if(temp->left != NULL){
        q.push(temp->left);
    }
    else{
        temp->left = createNode(data);
        return root;
    }
    if(temp->right != nullptr){
        q.push(temp->right);
    }
    else{
        temp->right = CreateNode(data);
        return root;
    }
}
return root;
// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // chọn pivot là số cuối cùng
    int i = low - 1;
    for (int j = low; j < high; j++) { // những số lớn hơn pivot thì đổi chỗ với những số lớn hơn pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // đem pivot vô giữa chia đôi ra
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); // đệ quy cho nửa trái
        quickSort(arr, pi + 1, high); // đệ quy cho nửa phải
    }
}
 
 // Functions for Tree Traversals

// 1. Pre-order Traversal (Root → Left → Right)
void preorder(Node* node) {
    if (node) {
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// 2. In-order Traversal (Left → Root → Right)
void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

// 3. Post-order Traversal (Left → Right → Root)
void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->key << " ";
    }
}

// Function for Tree Traversals
// pre-order traversal (Root - Left -right)
OK 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the structure for a BST node
struct ZodiacNode {
    string name; // Name of the zodiac sign
    vector<string> compatibleSigns; // List of compatible signs
    ZodiacNode* left; // Pointer to the left child
    ZodiacNode* right; // Pointer to the right child

    ZodiacNode(string n, vector<string> compatible)
        : name(n), compatibleSigns(compatible), left(nullptr), right(nullptr) {}
};

class ZodiacBST {
private:
    ZodiacNode* root;

    // Helper function for inserting a node into the BST
    ZodiacNode* insert(ZodiacNode* node, string name, vector<string> compatible) {
        if (node == nullptr) {
            return new ZodiacNode(name, compatible);
        }
        if (name < node->name) {
            node->left = insert(node->left, name, compatible);
        } else if (name > node->name) {
            node->right = insert(node->right, name, compatible);
        }
        return node;
    }

    // Helper function for displaying the BST in-order
    void inorderTraversal(ZodiacNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << "Zodiac: " << node->name << "\nCompatible Signs: ";
        for (const string& sign : node->compatibleSigns) {
            cout << sign << ", ";
        }
        cout << "\n----------------------\n";
        inorderTraversal(node->right);
    }

    // Helper function to check compatibility between two zodiac signs
    bool isCompatible(ZodiacNode* node, const string& name1, const string& name2) {
        if (node == nullptr) return false;
        if (node->name == name1) {
            for (const string& sign : node->compatibleSigns) {
                if (sign == name2) return true;
            }
            return false;
        }
        if (name1 < node->name) return isCompatible(node->left, name1, name2);
        return isCompatible(node->right, name1, name2);
    }

public:
    ZodiacBST() : root(nullptr) {}

    // Function to insert a new zodiac sign into the BST
    void insert(string name, vector<string> compatible) {
        root = insert(root, name, compatible);
    }

    // Function to check compatibility between two zodiac signs
    bool isCompatible(const string& name1, const string& name2) {
        return isCompatible(root, name1, name2);
    }

    // Function to display all zodiac signs and their compatible signs
    void display() {
        inorderTraversal(root);
    }
};

int main() {
    ZodiacBST zodiacTree;

    // Example data: Insert zodiac signs and their compatibility
    zodiacTree.insert("Aries", {"Leo", "Sagittarius", "Gemini", "Libra", "Aquarius"});
    zodiacTree.insert("Taurus", {"Virgo", "Capricorn", "Cancer", "Scorpio", "Pisces"});
    zodiacTree.insert("Gemini", {"Libra", "Aquarius", "Aries", "Leo", "Sagittarius"});
    zodiacTree.insert("Cancer", {"Scorpio", "Pisces", "Taurus", "Virgo", "Capricorn"});
    zodiacTree.insert("Leo", {"Aries", "Sagittarius", "Gemini", "Libra", "Aquarius"});
    zodiacTree.insert("Virgo", {"Taurus", "Capricorn", "Cancer", "Scorpio", "Pisces"});
    zodiacTree.insert("Libra", {"Gemini", "Aquarius", "Aries", "Leo", "Sagittarius"});
    zodiacTree.insert("Scorpio", {"Cancer", "Pisces", "Taurus", "Virgo", "Capricorn"});
    zodiacTree.insert("Sagittarius", {"Aries", "Leo", "Gemini", "Libra", "Aquarius"});
    zodiacTree.insert("Capricorn", {"Taurus", "Virgo", "Cancer", "Scorpio", "Pisces"});
    zodiacTree.insert("Aquarius", {"Gemini", "Libra", "Aries", "Leo", "Sagittarius"});
    zodiacTree.insert("Pisces", {"Cancer", "Scorpio", "Taurus", "Virgo", "Capricorn"});

    // Display all zodiac signs
    cout << "Displaying all zodiac signs and their compatible signs:\n";
    zodiacTree.display();

    // Check compatibility
    string zodiac1 = "Aries", zodiac2 = "Leo";
    cout << "\nAre " << zodiac1 << " and " << zodiac2 << " compatible? ";
    if (zodiacTree.isCompatible(zodiac1, zodiac2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    zodiac1 = "Cancer", zodiac2 = "Aquarius";
    cout << "\nAre " << zodiac1 << " and " << zodiac2 << " compatible? ";
    if (zodiacTree.isCompatible(zodiac1, zodiac2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}