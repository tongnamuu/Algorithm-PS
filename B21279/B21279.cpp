#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100001
struct D {
    int x, y;
    long long v;
    bool operator<(const D& a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
};
vector<D>a[N];
vector<D>b[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, c; cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        int x, y; long long v;
        cin >> x >> y >> v;
        a[x].push_back({ x,y,v });
        b[y].push_back({ x,y,v });
    }
    int s = -1, e = N - 1, cnt = 0;
    long long val = 0, ans = 0;
    while (s < N && e >= 0) {
        if (cnt <= c && s + 1 < N) {
            ++s;
            for (D& d : a[s]) {
                if (d.y <= e) {
                    cnt++;
                    val += d.v;
                }
            }
        }
        else {
            for (D& d : b[e]) {
                if (d.x <= s) {
                    cnt--;
                    val -= d.v;
                }
            }
            e--;
        }
        if (cnt <= c) ans = max(ans, val);
    }
    cout << ans;
}
