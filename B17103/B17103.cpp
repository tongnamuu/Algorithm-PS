#include <iostream>
#include <vector>
using namespace std;
bool check[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int>p;
	check[0] = check[1] = true;
	for (int i = 2; i <= 1000000; ++i) {
		if (!check[i]) {
			p.push_back(i);
			for (int j = i + i; j <= 1000000; j += i) check[j] = true;
		}
	}
	int pn = p.size();
	int T; cin >> T;
	int n;
	int ans;
	while (T--) {
		cin >> n;
		ans = 0;
		for (int i = 0; i < pn; ++i) {
			if (n-p[i]>=2 && p[i] <= n - p[i]) {
				if(!check[n - p[i]])++ans;
			}
			else break;
		}
		cout << ans << '\n';
	}
}