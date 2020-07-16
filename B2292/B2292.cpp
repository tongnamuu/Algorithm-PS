#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int cnt = 1;
    int res = 6;
    int ans = 1;
    while (cnt < n) {
        cnt += res;
        res += 6;
        ans++;
    }
    cout << ans;
}