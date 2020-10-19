#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int abs_diff_term = 2000000000;
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(a, a + n, -a[i]) - a;
        for (int j = -1; j <= 1; ++j) {
            int index = idx + j;
            if (index >= 0 && index < n&&i != index) {
                int diff = abs(a[i] + a[index]);
                if (diff < abs_diff_term) {
                    abs_diff_term = diff;
                    ans = a[i] + a[index];
                }
            }
        }
    }
    cout << ans;
}