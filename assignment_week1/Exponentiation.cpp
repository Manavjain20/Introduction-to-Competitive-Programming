#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (int i = 0; i < n; ++i) {
        long long a = queries[i].first;
        long long b = queries[i].second;
        cout << mod_exp(a, b, MOD) << endl;
    }

    return 0;
}
