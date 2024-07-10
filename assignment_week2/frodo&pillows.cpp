#include <iostream>
#include <vector>
using namespace std;

bool canHavePillows(int k, int n, int m, int p) {
    // Ensure Frodo's neighbors don't have significantly fewer pillows
    int leftPillows = p / 2;
    int rightPillows = p / 2;
    if (p % 2 == 1) {
        if (k > 1) leftPillows++;
        if (k < n) rightPillows++;
    }
    return (leftPillows + rightPillows <= m);
}

int maxPillows(int k, int n, int m) {
    int left = 1, right = m;
    int ans = 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canHavePillows(k, n, m, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int max_pillows = maxPillows(k, n, m);
    cout << max_pillows << endl;
    
    return 0;
}
