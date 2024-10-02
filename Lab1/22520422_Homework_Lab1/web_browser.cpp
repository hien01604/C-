// 22520422
// Pham Thi Minh Hien
// exercise 2 - homework

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
    BrowserHistory* browserHistory = new BrowserHistory("uit.edu.vn");

    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");
    
    cout << browserHistory->back(1) << endl;   // Output: facebook.com
    cout << browserHistory->back(1) << endl;   // Output: google.com
    cout << browserHistory->forward(1) << endl; // Output: facebook.com
    browserHistory->visit("linkedin.com");
    cout << browserHistory->forward(2) << endl; // Output: linkedin.com
    cout << browserHistory->back(2) << endl;    // Output: google.com
    cout << browserHistory->back(7) << endl;    // Output: uit.edu.vn
    
    return 0;
}
