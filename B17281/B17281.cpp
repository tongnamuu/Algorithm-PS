#include <iostream>
#include <algorithm>
using namespace std;
int a[10][51];
int solve(int n, int d[]) {
	int score = 0;
	int playerindex = 0;
	int outCnt = 0;
	for (int round = 1; round <= n; ++round) {
		int field[4] = { 0, };
		int i = playerindex + 1;
		outCnt = 0;
		for (; true; ++i) {
			if (i == 10) i = 1;
			if (a[d[i]][round] == 0) {
				outCnt++;
				if (outCnt == 3) {
					break;
				}
			}
			else if (a[d[i]][round] > 0) {
				int move = a[d[i]][round];
				for (int pos = 3; pos >= 1; --pos) {
					if (field[pos] > 0) {
						if (pos + move >= 4) {
							field[pos] = 0;
							++score;
						}
						else {
							field[pos] = 0;
							field[pos + move] = 1;
						}
					}
				}
				if (move < 4) field[move] = 1;
				else if (move == 4) ++score;
			}
		}
		playerindex = i;
	}
	return score;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cin >> a[j][i];
		}
	}
	int d[] = { 0,1,2,3,4,5,6,7,8,9 };
	int ans = 0;
	do {
		if (d[4] != 1) continue;
		int score = solve(n, d);
		if (ans < score) {
			ans = score;
		}
	} while (next_permutation(d + 1, d + 10));
	cout << ans << '\n';
}