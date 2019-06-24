#include <iostream>
#include <vector>
using namespace std;
bool check[100001];
vector<int>p;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	check[0] = check[1] = true;
	for (int i = 2; i <= 100000; ++i) {
		if (!check[i]) {
			p.push_back(i);
			for (int j = i + i; j <= 100000; j += j) {
				check[j] = true;
			}
		}
	}
	int T, n; cin >> T;
	while (T--) {
		cin >> n;
		for (int& k : p) {
			if (n == 1) break;
			int cnt = 0;
			while (n%k == 0) {
				n /= k;
				++cnt;
			}
			if(cnt>0) cout << k << ' ' << cnt << '\n';
		}
	}
}