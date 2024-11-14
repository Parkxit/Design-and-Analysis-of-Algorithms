 #include <iostream>
 #include <climits>
 using namespace std;
 void bellmanFord(int V, int E, int edges[][3], int src) 
    {
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // Set distance to all vertices as infinite
    }
    dist[src] = 0;  // Distance to source vertex is 0
    // Step 2: Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) 
   {
        for (int j = 0; j < E; j++) 
 {
            int u = edges[j][0];  // Source vertex of the edge
            int v = edges[j][1];  // Destination vertex of the edge
            int weight = edges[j][2];  // Weight of the edge
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
       {
                dist[v] = dist[u] + weight;
            }
        }
    }
    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) 
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
   {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    // Print the result
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
 }
 
 int main() 
{
    int V, E;
    // Get the number of vertices and edges from the user
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    // Declare an array to store the edges, each edge is represented by (source, 
destination, weight)
    int edges[E][3];
    // Get the edges from the user
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) 
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    // Get the source vertex from the user
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    // Run the Bellman-Ford algorithm
    bellmanFord(V, E, edges, src);
    return 0;
}
