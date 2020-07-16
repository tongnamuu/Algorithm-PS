#include <iostream>
using namespace std;
char a[65][65];
void solve(int sx, int ex, int sy, int ey) {
    int mx = sx + ex >> 1;
    int my = sy + ey >> 1;
    bool is_one = true;
    bool is_zero = true;
    for (int i = sx; i <= ex; ++i) {
        for (int j = sy; j <= ey; ++j) {
            if (a[i][j] == '1') is_zero = false;
            if (a[i][j] == '0') is_one = false;
        }
    }
    if (is_one) {
        cout << 1;
        return;
    }
    if (is_zero) {
        cout << 0;
        return;
    }
    cout << '(';
    solve(sx, mx, sy, my);
    solve(sx, mx, my + 1, ey);
    solve(mx + 1, ex, sy, my);
    solve(mx + 1, ex, my + 1, ey);
    cout << ')';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    solve(0, n - 1, 0, n - 1);
}