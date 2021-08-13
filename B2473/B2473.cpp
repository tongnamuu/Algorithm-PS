#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<long long>a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int x, y, z;
    long long diff = 1000000000000LL;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int idx = lower_bound(a.begin() + j + 1, a.end(), -a[i] - a[j]) - a.begin();
            if (idx < n && abs(a[i] + a[j] + a[idx]) < diff) {
                diff = abs(a[i] + a[j] + a[idx]);
                x = i, y = j, z = idx;
            }
            if (idx - 1 < n && idx -1 > j && abs(a[i] + a[j] + a[idx - 1]) < diff) {
                diff = abs(a[i] + a[j] + a[idx - 1]);
                x = i, y = j, z = idx - 1;
            }
        }
    }
    cout << a[x] << ' ' << a[y] << ' ' << a[z];
}