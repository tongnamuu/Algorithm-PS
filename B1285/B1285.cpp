#include <iostream>
using namespace std;
char a[21][21];
char reverse_coin(char x) {
    if (x == 'T') return 'H';
    else if (x == 'H') return 'T';
    return x;
}
int min(int x, int y) { return x > y ? y : x; }
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 2147483647;
    for (int k = 0; k<(1<<n);++k){
        for (int i = 0; i < n; ++i) {
            if (!(k&(1 << i))) continue;
            for (int j = 0; j < n; ++j) {
                a[i][j] = reverse_coin(a[i][j]);
            }
        }
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            int temp = 0;
            for (int i = 0; i < n; ++i) {
                temp += (a[i][j] == 'T');
            }
            if (temp > n - temp) temp = n - temp;
            cnt += temp;
        }
        ans = min(ans, cnt);
        for (int i = 0; i < n; ++i) {
            if (!(k&(1 << i))) continue;
            for (int j = 0; j < n; ++j) {
                a[i][j] = reverse_coin(a[i][j]);
            }
        }
    }
    cout << ans;
}
