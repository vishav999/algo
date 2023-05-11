#include <iostream>
#include <vector>

using namespace std;

// define an item structure
struct Item {
    int weight, value;
};

// find the maximum value that can be obtained by filling a knapsack of capacity W
int knapsack(vector<Item>& items, int W) {
    int n = items.size();

    // initialize memoization table
    vector<vector<int>> memo(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
            } else if (items[i - 1].weight <= j) {
                memo[i][j] = max(items[i - 1].value + memo[i - 1][j - items[i - 1].weight], memo[i - 1][j]);
            } else {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }

    return memo[n][W];
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int W = 50;

    cout << "Maximum value: " << knapsack(items, W) << endl;

    return 0;
}
