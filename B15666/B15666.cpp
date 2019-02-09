#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[10];
vector<int>temp;
vector<vector<int>>ans;
void go(int index, int cnt) {
	if (cnt == m) {
		ans.push_back(temp);
		return;
	}
	for (int i = index; i < n; ++i) {
		temp.push_back(a[i]);
		go(i, cnt + 1);
		temp.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		temp.push_back(a[i]);
		go(i, 1);
		temp.pop_back();
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (auto v : ans) {
		for (int i = 0; i < m; ++i) cout << v[i] << ' ';
		cout << '\n';
	}
}