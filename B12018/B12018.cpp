#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int>hubo;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		vector<int>mil;
		for (int j = 0, val; j < a; ++j) {
			cin >> val;
			mil.push_back(val);
		}
		sort(mil.begin(),mil.end());
		if (b > a) hubo.push_back(1);
		else hubo.push_back(mil[a - b]);
	}
	sort(hubo.begin(), hubo.end());
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < hubo.size(); ++i) {
		sum += hubo[i];
		if (sum > m) break;
		++cnt;
	}
	cout << cnt << '\n';
}