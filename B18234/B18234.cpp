#include <iostream>
#include <algorithm>
using namespace std;
#define N 200001
pair<long long, long long>a[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, T; cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (T - n + i)*a[i].first + a[i].second;
    }
    cout << ans;
}
