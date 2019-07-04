#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[101];
int solve() {
	int n, m; cin >> n >> m;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		q.push({ i,a[i] });
	}
	sort(a, a + n);
	int index = n - 1;
	int cnt = 0;
	while (index >= 0) {
		if (q.front().second < a[index]) {
			q.push(q.front()); q.pop();
		}
		else {
			++cnt;
			--index;
			if (q.front().first == m) return cnt;
			q.pop();
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cout << solve() << '\n';
	}
}