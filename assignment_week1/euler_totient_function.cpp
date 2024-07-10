#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000000;

// Function to precompute totient function for all integers up to MAXN
void compute_totients(vector<int>& phi) {
    for (int i = 1; i <= MAXN; ++i) {
        phi[i] = i;
    }
    
    for (int i = 2; i <= MAXN; ++i) {
        if (phi[i] == i) { // i is a prime
            for (int j = i; j <= MAXN; j += i) {
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    vector<int> phi(MAXN + 1);
    compute_totients(phi);
    
    while (T--) {
        int n;
        cin >> n;
        cout << phi[n] << endl;
    }
    
    return 0;
}
