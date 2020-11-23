#include <iostream>
using namespace std;
int a[130][130];
int all_same(int sx, int ex, int sy, int ey) {
    int c = a[sx][sy];
    for (int i = sx; i <= ex; ++i) {
        for (int j = sy; j <= ey; ++j) {
            if (a[i][j] != c) {
                return -1;
            }
        }
    }
    return c;
}
void solve(int& blue, int& white, int sx, int sy, int n) {
    int res = all_same(sx, sx + n - 1, sy, sy + n - 1);
    if (res == 1) {
        ++blue;
    }
    else if (res == 0) {
        ++white;
    }
    else {
        solve(blue, white, sx, sy, n / 2);
        solve(blue, white, sx + n / 2, sy, n / 2);
        solve(blue, white, sx, sy + n / 2, n / 2);
        solve(blue, white, sx + n / 2, sy + n / 2, n / 2);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    int blue = 0, white = 0;
    solve(blue, white, 0, 0, n);
    cout << white << '\n' << blue;
}
