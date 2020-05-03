#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, w; cin >> n >> w;
	vector<long long>three;
	three.push_back(0);
	vector<long long>five;
	five.push_back(0);
	for (int i = 0; i < n; ++i) {
		int c; long long v;
		cin >> c >> v;
		if (c == 3) three.push_back(v);
		else five.push_back(v);
	}
	sort(three.begin() + 1, three.end(), [](long long& u, long long& v) {
		return u > v;
	});
	sort(five.begin() + 1, five.end(), [](long long& u, long long& v) {
		return u > v;
	});
	for (int i = 1; i < three.size(); ++i) {
		three[i] += three[i - 1];
	}
	for (int i = 1; i < five.size(); ++i) {
		five[i] += five[i - 1];
	}
	int five_cnt = min((int)five.size() - 1, w / 5);
	long long ans = 0;
	for (int cnt = 0; cnt <= five_cnt; ++cnt) {
		int rest = w - cnt * 5;
		if (rest < 0) break;
		long long temp = five[cnt];
		int three_cnt = min((int)three.size() - 1, rest / 3);
		temp += three[three_cnt];
		ans = max(ans, temp);
	}
	cout << ans;
}