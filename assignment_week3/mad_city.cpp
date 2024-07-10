#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
int distA[MAXN], distB[MAXN];
int n;

void bfs(int start, int dist[]) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> n >> a >> b;
        
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            distA[i] = -1;
            distB[i] = -1;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            i
