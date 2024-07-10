#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; // store original positions
    }

    // Sort the array based on the first element of the pair
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            int target = x - (a[i].first + a[j].first);
            int left = j + 1, right = n - 1;
            while (left < right) {
                int sum = a[left].first + a[right].first;
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    cout << a[i].second << " " << a[j].second << " "
                         << a[left].second << " " << a[right].second << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
