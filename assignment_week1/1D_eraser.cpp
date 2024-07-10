#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int min_operations = n;
        int black_count = 0;

        for (int i = 0; i < k; ++i) {
            if (s[i] == 'B') {
                black_count++;
            }
        }

        min_operations = black_count;

        for (int i = k; i < n; ++i) {
            if (s[i - k] == 'B') {
                black_count--;
            }
            if (s[i] == 'B') {
                black_count++;
            }
            min_operations = min(min_operations, black_count);
        }

        cout << min_operations << endl;
    }
    return 0;
}
