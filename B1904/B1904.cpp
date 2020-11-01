#include <iostream>
using namespace std;
#define MOD 15746
int d[1000001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    d[1] = 1; d[2] = 2;
    for (int i = 3; i <= n; ++i)
        d[i] = (d[i - 1] + d[i - 2]) % MOD;
    cout << d[n];
}
