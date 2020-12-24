#include <iostream>
using namespace std;
int target[101];
int score[101];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> target[i];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1, name; j <= n; ++j) {
            cin >> name;
            int t = target[i];
            if (name == target[i]) {
                score[j]++;
            }
            else {
                score[t]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << score[i] << '\n';
    }
}
