#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int cnt[3];
int d[51][51][51][3][3];
int n;
bool track = false;
string ans;
string temp;
int solve(int a, int b, int c, int pprev, int prev) {
    if (track) return 1;
    int& res = d[a][b][c][pprev][prev];
    if (a + b + c == n) {
        ans = temp;
        track = true;
        return res = 1;
    }
    if (res != -1) return res;
    res = 0;
    if (cnt[0]) {
        cnt[0] -= 1;
        temp += 'A';
        if (solve(a + 1, b, c, prev, 0)==1) {
            res = 1;
            return res;
        }
        temp.pop_back();
        cnt[0] += 1;
    }

    if (cnt[1] && prev != 1) {
        cnt[1] -= 1;
        temp += 'B';
        if (solve(a, b+1, c, prev, 1)==1) {
            res = 1;
            return res;
        }
        temp.pop_back();
        cnt[1] += 1;
    }

    if (cnt[2] && prev!=2 && pprev!=2) {
        cnt[2] -= 1;
        temp += 'C';
        if (solve(a, b, c+1, prev, 2)==1) {
            res = 1;
            return res;
        }
        temp.pop_back();
        cnt[2] += 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s; cin >> s;
    n = s.length();
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'A']++;
    }
    if (solve(0, 0, 0, 0, 0) == 1) {
        cout << ans;
    }
    else {
        cout << -1;
    }
}
