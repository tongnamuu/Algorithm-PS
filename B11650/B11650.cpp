#include <iostream>
#include <algorithm>
using namespace std;
struct pos {
	int x, y;
	bool operator<(const pos& a) const {
		if (this->x != a.x) return this->x < a.x;
		else return this->y < a.y;
	}
};
pos d[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> d[i].x >> d[i].y;
	sort(d, d + n);
	for (int i = 0; i < n; ++i) cout << d[i].x << ' ' << d[i].y << '\n';
}