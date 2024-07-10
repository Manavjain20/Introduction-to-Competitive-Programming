#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> nails(n);
        for (int i = 0; i < n; ++i) {
            cin >> nails[i].first >> nails[i].second;
        }

        // Sort nails by their height in descending order
        sort(nails.rbegin(), nails.rend());

        int cuts = 0;
        int currentHeight = 0;

        for (int i = 0; i < n; ++i) {
            if (nails[i].first + nails[i].second > currentHeight) {
                cuts++;
                currentHeight = nails[i].first;
            }
        }

        cout << cuts << endl;
    }
    return 0;
}
