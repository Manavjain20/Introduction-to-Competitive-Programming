#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canComplete(int k, const vector<pair<int, int>>& segments) {
    int n = segments.size();
    long long current_end = 0;
    
    for (int i = 0; i < n; ++i) {
        if (current_end + k < segments[i].first) {
            return false;
        }
        current_end = max(current_end + k, (long long)segments[i].second);
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> segments(n);
        for (int i = 0; i < n; ++i) {
            cin >> segments[i].first >> segments[i].second;
        }
        
        sort(segments.begin(), segments.end());
        
        // Binary search on k
        int left = 0, right = segments.back().second - segments.front().first;
        int answer = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canComplete(mid, segments)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}
