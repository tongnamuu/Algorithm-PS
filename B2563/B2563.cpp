#include <iostream>
using namespace std;
int a[101][101];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (a[x + j][y + k] == 0) {
                    a[x + j][y + k] = 1;
                    ++ans;
                }
            }
        }
    }
    cout << ans;
}