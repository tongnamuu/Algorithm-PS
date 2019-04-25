#include <iostream>
#include <algorithm>
using namespace std;
struct pos {
	long long first, second;
	bool operator <(const pos& a) const {
		return this->second*a.first + a.second < this->first*a.second + this->second;
	}
};
pos a[200001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a, a + n);
		long long v = 1;
		for (int i = 0; i < n; ++i) {
			v = (a[i].first*v % 1000000007 + a[i].second % 1000000007) % 1000000007;
		}
		cout << '#' << test_case << ' ' << v << '\n';
	}
}