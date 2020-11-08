#include <iostream>
#include <algorithm>
using namespace std;
int a[500001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(i - a[i]);
    }
    cout << ans;
}
