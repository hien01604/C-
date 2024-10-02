// 22520422
// Pham Thi Minh Hien
// exercise 1 - homework

#include<iostream>
using namespace std;

// Define Node structure
struct Node {
    string song;
    Node* next;
};

typedef Node* node;

// Function to create a new node
node makeNode(string song) {
    node tmp = new Node();
    tmp->song = song;
    tmp->next = nullptr;
    return tmp;
}

// Add a song to the end of the playlist
void insertSong(node& head, string song) {
    node newNode = makeNode(song);
    if (head == nullptr) {
        head = newNode;
    } else {
        node tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

// Play the next song
void playNext(node& curr, node head) {
    if (curr == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }
    if (curr->next == nullptr) {
        curr = head; // Loop back to the first song
    } else {
        curr = curr->next; // Move to the next song
    }
}

// Play the previous song
void playPrevious(node& curr, node head) {
    if (curr == nullptr || head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }
    if (curr == head) {
        // Loop to the last song
        node tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        curr = tmp;
    } else {
        node tmp = head;
        while (tmp->next != curr) {
            tmp = tmp->next;
        }
        curr = tmp;
    }
}

// Remove a song by its name
void removeSong(node& head, string songName) {
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    node tmp = head, prev = nullptr;
    if (tmp != nullptr && tmp->song == songName) {
        head = tmp->next;
        delete tmp;
        return;
    }
    while (tmp != nullptr && tmp->song != songName) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == nullptr) {
        cout << "Song not found in the playlist." << endl;
        return;
    }
    prev->next = tmp->next;
    delete tmp;
}

// Display the playlist
void displayPlaylist(node head) {
    node tmp = head;
    while (tmp != nullptr) {
        cout << tmp->song << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    node head = nullptr, currentSong = nullptr;
    int n;
    cin >> n;  // Number of operations

    while (n--) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            string songName;
            cin >> ws;  // Clear whitespace
            getline(cin, songName);
            insertSong(head, songName);
            if (currentSong == nullptr) {
                currentSong = head;  // Start playing from the first song
            }
        } else if (operation == "NEXT") {
            playNext(currentSong, head);
        } else if (operation == "REMOVE") {
            string songName;
            cin >> ws;  // Clear whitespace
            getline(cin, songName);
            removeSong(head, songName);
        } else if (operation == "DISPLAY") {
            displayPlaylist(head);
        }
    }

    return 0;
}

// 1. How would you handle edge cases, such as trying to remove a song that doesn’t exist?
// Before attempting to remove a song, traverse the list to search for the song. 
// If the song is not found, display a message indicating that the song doesn't exist. 
// This prevents unintended modifications. The logic already checks if the song exists before deletion, 
// ensuring no errors occur when the song isn’t found.

// 2. How can you efficiently loop back to the start or end of the list?
// A simple way to loop back is to maintain a pointer to the head (first node) of the list. 
// If you're at the last node and want to move to the next song, check if the next pointer is nullptr. 
// If it is, reset the current pointer to the head to start over.

// Alternatively, you can use a circular linked list where the last node points to the first node, 
// making looping easier and more efficient.

// 3. What data structure(s) would you use to implement this playlist, and why?
// A singly linked list is ideal due to its dynamic nature and ease of insertion/removal of songs. 
// If you need to move both forward and backward through the playlist, 
// a doubly linked list might be more efficient since it stores references to both the next and previous nodes.

// 4. How would you ensure that operations like NEXT and PREV are efficient, given the constraints?
// In a doubly linked list, both NEXT and PREV operations can be done in constant time (O(1)) 
// since each node has pointers to both the next and previous nodes, allowing immediate traversal in either direction 