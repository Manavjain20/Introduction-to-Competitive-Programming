#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;

void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, E, T;
    cin >> N >> E >> T;

    vector<vector<pii>> graph(N + 1);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }

    // Initialize distance vector with INF
    vector<int> dist(N + 1, INF);

    // Run Dijkstra's algorithm from exit cell E
    dijkstra(E, graph, dist);

    // Count the number of cells that can reach E within time T
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] <= T) {
            count++;
        }
    }

    // Output the result
    cout << count << endl;

    return 0;
}
