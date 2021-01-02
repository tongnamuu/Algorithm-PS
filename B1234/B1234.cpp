#include <iostream>
using namespace std;
int n, red, green, blue;
long long d[11][101][101][101];
long long combination[101][11];
long long comb(int n, int r) {
    long long ret = 1;
    
}
long long solve(int now, int r, int g, int b) {
    if (r < 0 || g < 0 || b < 0) return 0;
    if (now > n ) {
        return 1;
    }
    long long& ret = d[now][r][g][b];
    if (ret != -1) return ret;
    ret = 0;
    ret += solve(now + 1, r - now, g, b);
    ret += solve(now + 1, r, g - now, b);
    ret += solve(now + 1, r, g, b - now);

    if (!(now & 1)) {
        int cnt = now / 2;
        if (r >= cnt && g >= cnt) ret += solve(now + 1, r - cnt, g - cnt, b);
        if (g >= cnt && b >= cnt) ret += solve(now + 1, r, g - cnt, b - cnt);
        if (r >= cnt && b >= cnt) ret += solve(now + 1, r - cnt, g, b - cnt);
    }
    if (now % 3 == 0) {
        int cnt = now / 3;
        if (r >= cnt && b >= cnt && g >= cnt) ret += solve(now + 1, r - cnt, g - cnt, b - cnt);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> red >> green >> blue;
    memset(d, -1, sizeof(d));
    long long ans = solve(1, red, green, blue);
    cout << ans;
}