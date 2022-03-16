#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000
int d[51][51];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(i!=j) d[i][j] = INF;
        }
    }
    while (1) {
        int x, y; cin >> x >> y;
        if (x == -1 && y == -1) break;
        d[x][y] = 1;
        d[y][x] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int cnt = 2147483647;
    vector<int>ans;
    for (int i = 1; i <= n; ++i) {
        int temp = 0;
        for (int j = 1; j <= n; ++j) {
            if (d[i][j] != INF) {
                temp = max(temp, d[i][j]);
            }
        }
        if (temp < cnt) {
            ans.clear();
            cnt = temp;
            ans.push_back(i);
        }
        else if (temp == cnt) {
            ans.push_back(i);
        }
    }
    cout << cnt << ' ' << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}