#include <iostream>
#include <vector>
using namespace std;
bool truth[51];
int a[51][51];
bool party[51];
bool visit[51];
int n, m;
void solve(int truth_person) {
    visit[truth_person] = true;
    for (int i = 1; i <= m; ++i) {
        if (a[i][truth_person]) {
            party[i] = 1;
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] && !visit[j]) {
                    solve(j);
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    int true_cnt; cin >> true_cnt;
    vector<int>real(true_cnt);
    for (int i = 0; i < true_cnt; ++i) {
        cin >> real[i];
        truth[real[i]] = true;
    }
    for (int i = 1; i <= m; ++i) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int num; cin >> num;
            a[i][num] = 1;
        }
    }
    for (int p : real) {
        if (!visit[p]) solve(p);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) if (!party[i]) ++ans;
    cout << ans;
}
