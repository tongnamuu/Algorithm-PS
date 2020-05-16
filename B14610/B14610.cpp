#include <iostream>
#include <set>
using namespace std;
int rest[101];
set<int> solver[11];
int problem_solved[11];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        if (k == m || k == 0) {
            cout << "NO\n";
            return 0;
        }
        for (int j = 1, num; j <= m; ++j) {
            cin >> num;
            if (num == 1) {
                problem_solved[j] = 1;
                k--;
            }
            else if (num == -1 && k) {
                solver[j].insert(i);
            }
        }
        rest[i] = k;
    }
    for (int j = 1; j <= m; ++j){
        if (problem_solved[j]) continue;
        for (auto i = solver[j].begin(); i != solver[j].end(); ++i) {
            int  idx = *i;
            if (rest[idx]) {
                rest[idx]--;
                problem_solved[j] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (!problem_solved[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}