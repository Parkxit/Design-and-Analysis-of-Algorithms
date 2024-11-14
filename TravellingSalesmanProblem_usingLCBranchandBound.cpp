#include <iostream>
#include <limits>
using namespace std;

#define MAX 999
#define MAX_CITIES 10

class TravelingSalesman {

public:
    int M[MAX_CITIES][MAX_CITIES]; // Cost matrix
   int n; // Number of cities
    int minCost; // Minimum cost found
    int bestPath[MAX_CITIES]; // Best path found


    TravelingSalesman(int cities) {
    	n=cities;
    	minCost=MAX;
        for (int i = 0; i < n; i++) {
            bestPath[i] = -1; // Initialize best path
        }
    }

    void inputCostMatrix() {
        cout << "Enter the Cost Matrix (999 for Infinity):" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
    }


    void solve() {
        bool visited[MAX_CITIES] = {false}; // Track visited cities
        visited[0] = true; // Start from the first city
        int currentPath[MAX_CITIES]; // Track the current path
        currentPath[0] = 0; // Start from city 0
        branchAndBound(0, 0, 1, visited, currentPath); // Start the search
    }


    void branchAndBound(int currentCity, int currentCost, int level, bool visited[], int currentPath[]) {
    	
    	
        if (level == n && M[currentCity][0] != MAX) {
            // Return to starting city
            int totalCost = currentCost + M[currentCity][0]; 
            
            if (totalCost < minCost) {
                minCost = totalCost; // Update minimum cost
                // Update the best path
                for (int i = 0; i < n; i++) {
                    bestPath[i] = currentPath[i];
                }
                bestPath[n] = 0; // Complete the cycle by returning to starting city
            }
            return;
        }

        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (!visited[nextCity] && M[currentCity][nextCity] != MAX) {
                visited[nextCity] = true; // Mark as visited
                currentPath[level] = nextCity; // Add next city to current path
                branchAndBound(nextCity, currentCost + M[currentCity][nextCity], level + 1, visited, currentPath);
                visited[nextCity] = false; // Backtrack
            }
        }
    }
};


int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    if (n > MAX_CITIES) {
        cout << "The number of cities exceeds the maximum limit!" << endl;
        return 1;
    }

    TravelingSalesman tsp(n);
    tsp.inputCostMatrix();
    tsp.solve(); // Solve TSP

    // Output minimum cost and the best path
    cout << "Minimum Cost: " << tsp.minCost << endl;
    cout << "Best Path: ";
    for (int i = 0; i <= n; i++) {
        cout << tsp.bestPath[i] + 1; // Print city numbers starting from 1
        if (i < n) cout << " --> "; // Format output
    }
    cout << endl;

    return 0;
}

