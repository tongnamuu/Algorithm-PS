#include <iostream>
using namespace std;
long long a[10001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long s = 0, e = 2147483647;
    while (s <= e) {
        long long m = s + e >> 1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i] / m;
        }
        if (sum < k) e = m - 1;
        else s = m + 1;
    }
    cout << e;
}
