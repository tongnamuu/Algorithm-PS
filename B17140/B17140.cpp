#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
int a[101][101];
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int r, c, k; cin >> r >> c >> k;
    int n = 3, m = 3; r--; c--;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    while (cnt <= 100) {
        if (a[r][c] == k) {
            cout << cnt;
            return 0;
        }
        ++cnt;
        if (n >= m) {
            int newm = 0;
            for (int i = 0; i < n; ++i) {
                map<int, int> cnt;
                vector<int>arr;
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] > 0) {
                        cnt[a[i][j]]++;
                        arr.push_back(a[i][j]);
                    }
                }
                sort(arr.begin(), arr.end(), [&](int u, int v) {
                    if (cnt[u] == cnt[v]) return u < v;
                    return cnt[u] < cnt[v];
                });
                arr.erase(unique(arr.begin(), arr.end()), arr.end());
                int sz = arr.size();
                int idx = 0;
                for (int j = 0; j < sz; ++j) {
                    a[i][idx] = arr[j];
                    a[i][idx + 1] = cnt[arr[j]];
                    idx += 2;
                    if (idx >= 100) break;
                }
                while (idx < 100) {
                    a[i][idx++] = 0;
                }
                newm = max(min(2 * sz, 100), newm);
            }
            m = newm;
        }
        else {
            int newn = 0;
            for (int j = 0; j < m; ++j) {
                map<int, int> cnt;
                vector<int>arr;
                for (int i = 0; i < n; ++i) {
                    if (a[i][j] > 0) {
                        cnt[a[i][j]]++;
                        arr.push_back(a[i][j]);
                    }
                }
                sort(arr.begin(), arr.end(), [&](int u, int v) {
                    if (cnt[u] == cnt[v]) return u < v;
                    return cnt[u] < cnt[v];
                });
                arr.erase(unique(arr.begin(), arr.end()), arr.end());
                int sz = arr.size();
                int idx = 0;
                for (int i = 0; i < sz; ++i) {
                    a[idx][j] = arr[i];
                    a[idx + 1][j] = cnt[arr[i]];
                    idx += 2;
                    if (idx >= 100) break;
                }
                while (idx < 100) {
                    a[idx++][j] = 0;
                }
                newn = max(min(2 * sz, 100), newn);
            }
            n = newn;
        }
    }
    cout << -1;
}
