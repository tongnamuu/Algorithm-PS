#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long>d;
void solve(long long n) {
	while (n) {
		n -= n & -n;
		d.push_back(n);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long n; cin >> n;
	int m; cin >> m;
	solve(n);
	if (d.size() < m) {
		cout << -1;
		return 0;
	}
	vector<long long>ans;
	for (int i = d.size()-1; i>=0; --i) {
		if (ans.size() >= m) break;
		ans.push_back(d[i]);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}