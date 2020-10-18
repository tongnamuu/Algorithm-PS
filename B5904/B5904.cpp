#include <iostream>
#include <string>
using namespace std;
char solve(long long len, int idx, int k) {
    if (len == 3) {
        if (idx == 0) return 'm';
        else return 'o';
    }
    int f = (len - (k + 3)) / 2;
    int s = f + k + 3;
    if (idx < f) {
        return solve(f, idx, k - 1);
    }
    else if (idx < s) {
        if (idx - f == 0) return 'm';
        else return 'o';
    }
    else {
        return solve(f, idx - s, k - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    if (n == 1) {
        cout << 'm'; return 0;
    }
    else if (n == 2 || n == 3) {
        cout << 'o'; return 0;
    }
    int idx = 0;
    int len = 0;
    while (n > len) {
        len = 2 * len + idx + 3;
        idx += 1;
    }
    cout << solve(len, n - 1, idx - 1);
}