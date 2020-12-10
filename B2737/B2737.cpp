#include <iostream>
#include <vector>
using namespace std;
void init(int n) {
    int ans = 0;
    for (long long i = 1; i*i <= n; i++) {
        long long k = i;
        long long up = 2 * n - k * k - k;
        long long down = 2 * k;
        if (k!=1 && up>=0 && up % down == 0) {
            ++ans;
        }
        if (i*i == n) continue;
        k = n / i;
        up = 2 * n - k * k - k;
        down = 2 * k;
        if (k != 1 && up >= 0 && up % down == 0) {
            ++ans;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        init(n);
    }
}