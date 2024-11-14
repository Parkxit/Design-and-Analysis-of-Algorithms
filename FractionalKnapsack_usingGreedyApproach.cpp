
#include <iostream>
using namespace std;

int maximum(float a[], int n) {
    int maxIndex = 0;  // Index of the maximum value in the ratio array
    for (int i = 1; i < n; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int n = 0;
    cout << "Enter the number of items that you want to enter: ";
    cin >> n;

    float capacity;
    cout << "Enter the maximum capacity of the bag: ";
    cin >> capacity;

    float profit[n], weight[n];
    cout << "Enter the profit and weight for each item:\nNOTE: Enter the profit first and then the weight:\n";

    for (int i = 0; i < n; i++) {
        cin >> profit[i] >> weight[i];
    }

    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    float output[n] = {0};
    float p = 0;
    
    // Process items by highest ratio
    for (int i = 0; i < n; i++) {
        int max = maximum(ratio, n);
        if (weight[max] <= capacity) {
            capacity -= weight[max];
            p += profit[max];
            output[max] = 1;
        } else {
            float factor = capacity / weight[max];
            p += profit[max] * factor;
            output[max] = factor;
            capacity = 0;
        }
        ratio[max] = -1;  // Mark this item as processed
    }

    cout << "Output array is:\n";
    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << "\n";
    cout << "Max profit is " << p << endl;

    return 0;
}
