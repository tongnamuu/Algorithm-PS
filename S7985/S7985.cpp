#include <iostream>
#include <vector>
using namespace std;
const int d[] = { 0,1,3,7,15,31,63,127,255,511,1023 };
int a[1100];
vector<int>ans[11];
int n;
void solve(int start, int end, int index) {
	if (index == n) return;
	int mid = (start + end) / 2;
	ans[index].push_back(a[mid]);
	solve(start, mid - 1, index + 1);
	solve(mid + 1, end, index + 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for (int i = 0; i < n; ++i) ans[i].clear();
		int k = d[n];
		for (int i = 0; i < k; ++i) cin >> a[i];
		solve(0, k - 1, 0);
		cout << '#' << tc << ' ';
		for (int i = 0; i < n; ++i) {
			for (int num : ans[i]) cout << num << ' ';
			cout << '\n';
		}
	}
}