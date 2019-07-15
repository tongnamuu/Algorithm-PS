#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
map<string, int>m;
int a[101][101];
int n;
int ans;
bool check(int index, vector<int>& team) {
	for (int player : team) {
		if (a[player][index] == 1) return false;
	}
	return true;
}
void go(int index, vector<int>& left, vector<int>& right) {
	if (ans > 0) return;
	if (index == n + 1) {
		if (left.size() > 0 && right.size() > 0) ++ans;
		return;
	}
	if (check(index, left)) {
		left.push_back(index);
		go(index + 1, left, right);
		left.pop_back();
	}
	if (check(index, right)) {
		right.push_back(index);
		go(index + 1, left, right);
		right.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	string p1, p2;
	for (int tc = 1; tc <= T; ++tc) {
		ans = 0;
		memset(a, 0, sizeof(a));
		cin >> n;
		int numbering = 1;
		m.clear();
		for (int i = 0; i < n; ++i) {
			cin >> p1 >> p2;
			if (m[p1] == 0) m[p1] = numbering++;
			if (m[p2] == 0) m[p2] = numbering++;
			a[m[p1]][m[p2]] = 1;
			a[m[p2]][m[p1]] = 1;
		}
		n = numbering - 1;
		vector<int>left;
		vector<int>right;
		left.push_back(1);
		go(2, left, right);
		if (ans) cout << '#' << tc << " Yes" << '\n';
		else cout << '#' << tc << " No" << '\n';
	}
}