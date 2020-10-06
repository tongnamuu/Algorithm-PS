#include <iostream>
using namespace std;
int main() {
    unsigned long long n; cin >> n;
    n = 18446744073709551615 - n + 1;
    int ans = 65;
    while (n) {
        n /= 2;
        --ans;
    }
    cout << ans;
}