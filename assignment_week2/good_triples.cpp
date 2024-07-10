#include <iostream>

using namespace std;

int digsum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int countGoodTriples(int n) {
    int goodTriples = 0;
    
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n; ++b) {
            int c = n - a - b;
            if (c >= 0 && digsum(a) + digsum(b) + digsum(c) == digsum(n)) {
                ++goodTriples;
            }
        }
    }
    
    return goodTriples;
}

int main() {
    int n;
    cin >> n;
    
    int result = countGoodTriples(n);
    cout << result << endl;
    
    return 0;
}
