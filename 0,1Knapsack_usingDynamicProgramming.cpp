#include <iostream>
using namespace std;

int knapsack(int capacity, int weight[], int profit[], int n, int output[]) {
    int dp[n+1][capacity+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if(weight[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i-1]] + profit[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int result = dp[n][capacity];
    int w = capacity;

    for(int i = n; i > 0 && result > 0; i--) {
        if(result != dp[i-1][w]) {
            output[i-1] = 1;
            result -= profit[i-1];
            w -= weight[i-1];
        } else {
            output[i-1] = 0;
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int profit[n];
    int weight[n];

    cout << "Enter profit of each item: ";
    for(int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weight of each item: ";
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int output[n] = {0};
    int maxProfit = knapsack(capacity, weight, profit, n, output);

    cout << "Max profit: " << maxProfit << endl;
    cout << "Selected items (1 means selected, 0 means not selected): ";
    for(int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    

    return 0;
}

