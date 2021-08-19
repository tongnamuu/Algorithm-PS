#include <iostream>
using namespace std;
int d[301][301];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> d[i][j];
            d[i][j] += (d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1]);
        }
    }
    cout << d[n][m];
}
