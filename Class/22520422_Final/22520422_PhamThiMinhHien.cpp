// Pham Thi Minh Hien
// 22520422
// stt: 14

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Create a linked list to represent the 12 zodiac signs
struct Zodiac {
    string name;
    string rulingPlanet;
    vector<string> traits;
    string startDate;
    string element; // Added element for compatibility
    Zodiac* next;
    Zodiac* prev;

    // Constructor for creating a new Zodiac node
    Zodiac(string name, string rulingPlanet, vector<string> traits, string startDate, string element)
        : name(name), rulingPlanet(rulingPlanet), traits(traits), startDate(startDate), element(element), next(nullptr), prev(nullptr) {}
};

// Zodiac list class
class ZodiacList {
private:
    Zodiac* head;
    Zodiac* tail;

public:
    ZodiacList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new zodiac sign at any position
    void insertZodiac(string name, string rulingPlanet, vector<string> traits, string startDate, string element, int position) {
        Zodiac* newZodiac = new Zodiac(name, rulingPlanet, traits, startDate, element);
        if (head == nullptr) { // Empty list
            head = tail = newZodiac;
        } else if (position == 0) { // Insert at the beginning
            newZodiac->next = head;
            head->prev = newZodiac;
            head = newZodiac;
        } else {
            Zodiac* temp = head;
            int index = 0;
            while (temp->next != nullptr && index < position - 1) {
                temp = temp->next;
                index++;
            }
            newZodiac->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = newZodiac;
            }
            temp->next = newZodiac;
            newZodiac->prev = temp;
            if (newZodiac->next == nullptr) {
                tail = newZodiac;
            }
        }
    }

    // Function to delete a zodiac sign by name
    void deleteZodiac(string name) {
        Zodiac* temp = head;
        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }
        if (temp == nullptr) { // Zodiac not found
            cout << "Zodiac sign not found.\n";
            return;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else { // Deleting the head
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else { // Deleting the tail
            tail = temp->prev;
        }
        delete temp;
        cout << "Zodiac sign deleted successfully.\n";
    }

    // Function to display all zodiac signs along with their traits
    void displayZodiacs() {
        Zodiac* temp = head;
        while (temp != nullptr) {
            cout << "Zodiac: " << temp->name << "\n";
            cout << "Ruling Planet: " << temp->rulingPlanet << "\n";
            cout << "Traits: ";
            for (const string& trait : temp->traits) {
                cout << trait << ", ";
            }
            cout << "\nStart Date: " << temp->startDate << "\n";
            cout << "Element: " << temp->element << "\n";
            cout << "----------------------\n";
            temp = temp->next;
        }
    }

    // Function to search for a zodiac sign by name using Interpolation Search
    string searchZodiacByName(string name) {
        vector<Zodiac*> zodiacArray;
        Zodiac* temp = head;

        // Copying linked list to an array for interpolation search
        while (temp != nullptr) {
            zodiacArray.push_back(temp);
            temp = temp->next;
        }

        int low = 0;
        int high = zodiacArray.size() - 1;

        while (low <= high && name >= zodiacArray[low]->name && name <= zodiacArray[high]->name) {
            if (low == high) {
                if (zodiacArray[low]->name == name) {
                    return formatZodiacInfo(zodiacArray[low]);
                }
                break;
            }

            int pos = low + (((double)(high - low) / (zodiacArray[high]->name[0] - zodiacArray[low]->name[0])) * (name[0] - zodiacArray[low]->name[0]));

            if (zodiacArray[pos]->name == name) {
                return formatZodiacInfo(zodiacArray[pos]);
            }

            if (zodiacArray[pos]->name < name) {
                low = pos + 1;
            } else {
                high = pos - 1;
            }
        }

        return "Not Found";
    }

    // Helper function to format zodiac information
    string formatZodiacInfo(Zodiac* zodiac) {
        string result = "Zodiac: " + zodiac->name + "\nRuling Planet: " + zodiac->rulingPlanet + "\nTraits: ";
        for (const string& trait : zodiac->traits) {
            result += trait + ", ";
        }
        result += "\nStart Date: " + zodiac->startDate;
        return result;
    }

    // Function to return all zodiac signs whose names start with a given letter
    vector<string> getZodiacByInitial(char initial) {
        vector<string> results;
        Zodiac* temp = head;
        while (temp != nullptr) {
            if (temp->name[0] == initial) {
                results.push_back(temp->name);
            }
            temp = temp->next;
        }
        return results;
    }

    // Function to calculate compatibility score based on elemental associations
    pair<int, string> calculateCompatibility(string zodiac1, string zodiac2) {
        Zodiac* z1 = searchZodiacNode(zodiac1);
        Zodiac* z2 = searchZodiacNode(zodiac2);

        if (z1 == nullptr || z2 == nullptr) {
            return {0, "One or both zodiac signs do not exist in the list."};
        }

        // Compatibility logic based on elemental associations
        if (z1->element == z2->element) {
            return {90, "High compatibility: Both signs share the same element."};
        } else if ((z1->element == "Fire" && z2->element == "Air") ||
                   (z1->element == "Air" && z2->element == "Fire") ||
                   (z1->element == "Earth" && z2->element == "Water") ||
                   (z1->element == "Water" && z2->element == "Earth")) {
            return {75, "Good compatibility: Complementary elements."};
        } else {
            return {50, "Moderate compatibility: Different elemental associations."};
        }
    }

    Zodiac* searchZodiacNode(string name) {
        Zodiac* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    ~ZodiacList() {
        Zodiac* temp = head;
        while (temp != nullptr) {
            Zodiac* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Define the structure for a BST node
struct ZodiacNode {
    string name;
    vector<string> compatibleSigns;
    ZodiacNode* left;
    ZodiacNode* right;

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

    // Helper function for in-order traversal
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

public:
    ZodiacBST() : root(nullptr) {}

    void insert(string name, vector<string> compatible) {
        root = insert(root, name, compatible);
    }

    void display() {
        inorderTraversal(root);
    }

    ~ZodiacBST() {
        deleteTree(root);
    }

    void deleteTree(ZodiacNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    ZodiacList zodiacList;

    // Example data with start dates and elements
    zodiacList.insertZodiac("Aries", "Mars", {"Assertive", "Pioneering", "Energetic"}, "March 21", "Fire", 0);
    zodiacList.insertZodiac("Taurus", "Venus", {"Stable", "Loyal", "Artistic"}, "April 20", "Earth", 1);
    zodiacList.insertZodiac("Gemini", "Mercury", {"Adaptable", "Communicative", "Witty"}, "May 21", "Air", 2);

    cout << "Displaying all zodiac signs:\n";
    zodiacList.displayZodiacs();

    // Searching for a zodiac sign using Interpolation Search
    cout << "\nSearching for Gemini using Interpolation Search...\n";
    cout << zodiacList.searchZodiacByName("Gemini") << "\n";

    // Getting zodiac signs starting with a letter
    cout << "\nGetting all zodiac signs starting with 'A'...\n";
    vector<string> results = zodiacList.getZodiacByInitial('A');
    for (const string& name : results) {
        cout << name << "\n";
    }

    // Calculating compatibility
    cout << "\nCalculating compatibility between Aries and Taurus...\n";
    auto compatibility = zodiacList.calculateCompatibility("Aries", "Taurus");
    cout << "Score: " << compatibility.first << "\nExplanation: " << compatibility.second << "\n";

    // Using the BST to check compatibility
    ZodiacBST bst;
    bst.insert("Aries", {"Leo", "Sagittarius"});
    bst.insert("Taurus", {"Virgo", "Capricorn"});
    bst.insert("Gemini", {"Libra", "Aquarius"});
    cout << "\nDisplaying zodiac compatibility from BST:\n";
    bst.display();

    return 0;
}