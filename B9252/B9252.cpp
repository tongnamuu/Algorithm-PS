#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int d[1001][1001];
int max(int a, int b) { return a > b ? a : b; }
int max3(int a, int b, int c) {
	return max(max(a, b), c);
}
int lower_bound(int * a, int size, int val) {
	int start = 0, end = size - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] >= val) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s, p; cin >> s >> p;
	int len1 = s.length();
	int len2 = p.length();
	queue<pair<int, int>>q;
	bool find = false;
	for (int i = 0; i < len1; ++i) {
		if (find) d[i][0] = 1;
		if (p[0] == s[i]) {
			find = true;
			d[i][0] = 1;
		}
	}
	find = false;
	for (int i = 0; i < len2; ++i) {
		if (find) d[0][i] = 1;
		if (s[0] == p[i]) {
			find = true;
			d[0][i] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i < len1; ++i) {
		for (int j = 1; j < len2; ++j) {
			d[i][j] = max3(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] + (s[i] == p[j]));
			if (ans < d[i][j]) ans = d[i][j];
		}
	}
	cout << ans << '\n';
	vector<char>prev;
	int cur = ans;
	for (int i = len1 - 1; i >= 0; --i) {
		if (cur == 0) break;
		int index = lower_bound(d[i], len2, cur);
		if (index < len2 && s[i] == p[index]) {
			prev.push_back(s[i]);
			cur--;
		}
	}
	for (int i = prev.size() - 1; i >= 0; --i) cout << prev[i];
}