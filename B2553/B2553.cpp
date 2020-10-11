#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long ans = 1;
    for (long long i = 2; i <= n; ++i) {
        ans *= i;
        while (ans % 10 == 0) ans /= 10;
        ans %= 100000000;
    }
    cout << ans % 10;
}