#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(vector<vector<int>>& dist, int n) {
    // Initialize distances based on the adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == 0 && i != j) {
                dist[i][j] = INF; // No direct road, set distance to infinity
            }
        }
    }
    
    // Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> H(n, vector<int>(n));
    
    // Input the adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> H[i][j];
        }
    }
    
    // Compute shortest paths using Floyd-Warshall
    floydWarshall(H, n);
    
    // Output results
    for (int i = 0; i < n; ++i) {
        if (H[i][i] == INF) {
            cout << "NO WAY" << endl;
        } else {
            cout << H[i][i] << endl;
        }
    }
    
    return 0;
}
