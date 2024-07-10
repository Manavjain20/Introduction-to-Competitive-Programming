#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int in_degree[MAXN];
vector<int> topo_order;

void topological_sort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    
    topological_sort(n);
    
    if (topo_order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << topo_order[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
