#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentUrl;

public:
    BrowserHistory(string homepage) {
        currentUrl = homepage;
        while (!forwardStack.empty()) forwardStack.pop(); // Clear forward history
    }

    void visit(string url) {
        backStack.push(currentUrl);  // Push current to backStack before visiting new
        currentUrl = url;
        while (!forwardStack.empty()) forwardStack.pop(); // Clear forward history
    }

    string back(int steps) {
        while (steps > 0 && !backStack.empty()) {
            forwardStack.push(currentUrl);
            currentUrl = backStack.top();
            backStack.pop();
            steps--;
        }
        return currentUrl;
    }

    string forward(int steps) {
        while (steps > 0 && !forwardStack.empty()) {
            backStack.push(currentUrl);
            currentUrl = forwardStack.top();
            forwardStack.pop();
            steps--;
        }
        return currentUrl;
    }
};

int main() {
    string homepage;
    cout << "Enter the homepage URL: ";
    cin >> homepage;
    BrowserHistory* browserHistory = new BrowserHistory(homepage);

    int choice, steps;
    string url;

    while (true) {
        cout << "\nChoose an operation:\n1. Visit a new URL\n2. Go back\n3. Go forward\n4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter URL to visit: ";
            cin >> url;
            browserHistory->visit(url);
            cout << "Visited: " << url << endl;
            break;
        case 2:
            cout << "Enter number of steps to go back: ";
            cin >> steps;
            cout << "Current URL after going back: " << browserHistory->back(steps) << endl;
            break;
        case 3:
            cout << "Enter number of steps to go forward: ";
            cin >> steps;
            cout << "Current URL after going forward: " << browserHistory->forward(steps) << endl;
            break;
        case 4:
            cout << "Exiting the browser history simulation." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
