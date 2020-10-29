#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[2001];
bool check[2001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val = a[i] + a[j];
            int idx = lower_bound(a, a + n, val) - a;
            if (!(idx < n && a[idx] == val)) continue;
            if (check[idx]) continue;
            if (!a[i] && !a[j]) {
                int idx2 = upper_bound(a, a + n, val) - a;
                if (idx2 - idx > 2) {
                    check[idx] = true;
                }
            }
            else if (!a[i] || !a[j]) {
                int idx2 = upper_bound(a, a + n, val) - a;
                if (idx2 - idx >= 2) {
                    check[idx] = true;
                }
            }
            else {
                check[idx] = true;
            }
        }
    }
    int ans = 0;
    int val = 1000000001;
    for (int i = 0; i < n; ++i) {
        if (check[i]) {
            ++ans;
            val = a[i];
        }
        else {
            if (a[i] == val) {
                ++ans;
                check[i] = true;
            }
        }
    }
    cout << ans;
}