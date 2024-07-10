#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> depth;

void buildTree(int l, int r, int currentDepth) {
    if (l > r) return;
    
    int maxIndex = l;
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }
    
    depth[a[maxIndex]] = currentDepth;
    
    buildTree(l, maxIndex - 1, currentDepth + 1);
    buildTree(maxIndex + 1, r, currentDepth + 1);
}

int main() {
    int n;
    cin >> n;
    
    a.resize(n + 1);
    depth.resize(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    // Finding the maximum element to start building the tree
    int maxIndex = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }
    
    // Build the tree starting from the maximum element
    buildTree(1, n, 0);
    
    // Output the depths of vertices
    for (int i = 1; i <= n; ++i) {
        cout << depth[i] << " ";
    }
    cout << endl;
    
    return 0;
}
