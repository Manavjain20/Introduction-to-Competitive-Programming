#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s;
    cin >> k >> s;

    int n = s.size();
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + (s[i] == '1');
    }

    unordered_map<int, long long> prefixCount;
    long long result = 0;
    for (int i = 0; i <= n; ++i) {
        if (prefixCount.find(prefixSum[i] - k) != prefixCount.end()) {
            result += prefixCount[prefixSum[i] - k];
        }
        prefixCount[prefixSum[i]]++;
    }

    cout << result << "\n";

    return 0;
}
