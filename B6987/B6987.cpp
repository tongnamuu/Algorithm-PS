#include <iostream>
using namespace std;
int a[6][3];
int score[6][3];
bool fill(int x, int y, int cur) {
    if (cur == 15) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] != score[i][j]) return false;
            }
        }
        return true;
    }
    if (y >= 6) return fill(x + 1, x + 2, cur);
    bool res = false;
    score[x][0] += 1;
    score[y][2] += 1;
    if(score[x][0] <= a[x][0] && score[y][2] <= a[y][2])
        res |= fill(x, y + 1, cur + 1);
    score[x][0] -= 1;
    score[y][2] -= 1;

    score[x][1] += 1;
    score[y][1] += 1;
    if (score[x][1] <= a[x][1] && score[y][1] <= a[y][1])
        res |= fill(x, y + 1, cur + 1);
    score[x][1] -= 1;
    score[y][1] -= 1;

    score[x][2] += 1;
    score[y][0] += 1;
    if (score[x][2] <= a[x][2] && score[y][0] <= a[y][0])
        res |= fill(x, y + 1, cur + 1);
    score[x][2] -= 1;
    score[y][0] -= 1;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    for (int tc = 1; tc <= 4; ++tc) {
        bool ans = true;
        for (int i = 0; i < 6; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        if (fill(0, 1, 0)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
