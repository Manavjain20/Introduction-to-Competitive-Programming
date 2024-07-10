#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& dist) {
    int n = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pii>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        vector<int> dist(n + 1, INF);
        dijkstra(a, graph, dist);

        int shortest_path = dist[b];
        if (shortest_path == INF)
            cout << -1 << endl;
        else
            cout << shortest_path << endl;
    }

    return 0;
}
