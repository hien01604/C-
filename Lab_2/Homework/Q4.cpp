#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size(); // Number of fruits
        deque<int> q; // Deque to store indices of prices

        // Traverse prices in reverse order
        for (int i = n - 1; i >= 0; --i) {
            // Remove elements from the front that cannot be used
            while (!q.empty() && q.front() > i + 1) {
                q.pop_front();
            }

            // If we're in the left half of the prices, we can add the value
            if (i < n / 2) {
                prices[i] += prices[q.front() - 1];
            }

            // Remove elements from the back if they are greater than or equal to the current price
            while (!q.empty() && prices[q.back() - 1] >= prices[i]) {
                q.pop_back();
            }

            // Add the current index to the deque (1-based index for consistency)
            q.push_back(i + 1);
        }

        // The result will be the first element in the modified prices array
        return prices[0];
    }
};

int main() {
    Solution solution;

    int n; // Number of fruits
    cout << "Enter the number of fruits: ";
    cin >> n;

    vector<int> prices(n); // Vector to store prices of fruits
    cout << "Enter the prices of the fruits: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    // Call the method and output the result
    int result = solution.minimumCoins(prices);
    cout << "Minimum number of coins necessary: " << result << endl;

    return 0;
}
