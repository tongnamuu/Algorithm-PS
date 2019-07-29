#include <iostream>
#include <vector>
using namespace std;
int n;
int a[21][21];
int ans=2147483647;
int abs(int x, int y) { return x > y ? x - y : y - x; }
void go(int index, vector<int>& left, vector<int>& right,int lscore, int rscore) {
	if (index == n + 1) {
		if (abs(lscore, rscore) < ans) {
			ans = abs(lscore, rscore);
		}
		return;
	}
	left.push_back(index);
	int score = lscore;
	for (int team : left) {
		score += a[team][index];
		score += a[index][team];
	}
	go(index + 1, left, right, score, rscore);
	left.pop_back();
	right.push_back(index);
	score = rscore;
	for (int team : right) {
		score += a[team][index];
		score += a[index][team];
	}
	go(index + 1, left, right, lscore, score);
	right.pop_back();
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
	vector<int>left;
	vector<int>right;
	left.push_back(1);
	go(2, left, right, 0, 0);
	cout << ans << '\n';
}