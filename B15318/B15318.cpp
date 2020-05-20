#include <iostream>
using namespace std;
long long a[300001];
long long b[300001];
long long sum[300001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i & 1) sum[0] -= a[i];
        else sum[0] += a[i];
    }
    for (int i = 0, coef = 1; i < n; ++i, ++coef) {
        int op = (i & 1) ? -1 : 1;
        b[0] += op * coef*a[i];
    }
    if (n & 1) {
        for (int i = 0; i + 1 < n; ++i) {
            b[i + 1] = sum[i] + n * a[i] - b[i];
            sum[i + 1] = -sum[i] + 2 * a[i];
        }
    }
    else {
        for (int i = 0; i + 1 < n; ++i) {
            b[i + 1] = sum[0] - n * a[i] - b[i];
            sum[0] = -sum[0];
        }
    }
    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
}