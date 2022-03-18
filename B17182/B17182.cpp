#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[11][11];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    vector<int>p;
    p.push_back(x);
    for (int i = 0; i < n; ++i) {
        if (i != x) p.push_back(i);
    }
    int ans = 2147483647;
    do {
        int s = x;
        int temp = 0;
        for (int i = 1; i < n; ++i) {
            temp += a[s][p[i]];
            s = p[i];
        }
        ans = min(ans, temp);
    } while (next_permutation(p.begin() + 1, p.end()));
    cout << ans;
}