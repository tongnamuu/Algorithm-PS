#include <iostream>
using namespace std;
pair<int, int>a[151];
int pasture[151];
int n, m;
int solve(int now) {
    for (int p = 1; p <= 4; ++p) {
        bool go = true;
        for (int j = 0; j < m; ++j) {
            if (a[j].second == now && pasture[a[j].first] == p) {
                go = false;
            }
        }
        if (go) return p;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    for (int i = 1; i <= n; ++i) {
        pasture[i] = solve(i);
        cout << pasture[i];
    }
}
