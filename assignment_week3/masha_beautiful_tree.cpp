#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
        }

        // Calculate the minimum number of swaps required
        int swaps = 0;
        vector<int> current_order(m);
        for (int i = 0; i < m; ++i) {
            current_order[i] = i + 1;
        }

        for (int i = 0; i < m; ++i) {
            if (current_order[i] != p[i]) {
                swaps++;
            }
        }

        cout << swaps << endl;
    }

    return 0;
}
