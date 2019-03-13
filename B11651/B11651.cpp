#include <iostream>
#include <algorithm>
using namespace std;
struct pos {
	int x, y;
	bool operator<(const pos a) const {
		if (this->y == a.y) return this->x < a.x;
		else return this->y < a.y;
	}
};
pos a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) cout << a[i].x << ' ' << a[i].y << '\n';
}