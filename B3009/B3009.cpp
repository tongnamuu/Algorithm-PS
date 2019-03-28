#include <iostream>
#include <algorithm>
using namespace std;
struct pos {
	int first, second;
	bool operator<(const pos& a) const {
		if (this->first == a.first) return this->second < a.second;
		else return this->first < a.first;
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pos a[3];
	for (int i = 0; i < 3; ++i) cin >> a[i].first >> a[i].second;
	sort(a, a + 3);
	if (a[0].first == a[1].first) {
		cout << a[2].first << ' ';
		if (a[0].second == a[2].second) cout << a[1].second << ' ';
		else cout << a[0].second << ' ';
	}
	else {
		cout << a[0].first << ' ';
		if (a[0].second == a[2].second) cout << a[1].second << ' ';
		else cout << a[2].second << ' ';
	}
}