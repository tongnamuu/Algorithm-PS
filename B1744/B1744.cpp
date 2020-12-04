#include <iostream>
#include <algorithm>
using namespace std;
#define N 10001
int a[N];
int d[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    d[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        d[i] = max(d[i - 1] + a[i], d[i - 2] + a[i - 1] * a[i]);
    }
    cout << d[n];
}
