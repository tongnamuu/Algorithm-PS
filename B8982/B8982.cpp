#include <iostream>
#include <algorithm>
using namespace std;
int a[40001];
int startpos[40001];
struct Hole {
	int start, end, pos;
	bool operator<(const Hole& a) const {
		return this->pos < a.pos;
	}
};
Hole hole[2501];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int u, v; cin >> u >> v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		if (i & 1) {
			a[u] = v + 1;
		}
	}
	for (int i = 0; i <= u; ++i) {
		if (a[i] == 0) {
			a[i] = a[i - 1];
		}
		else a[i]--;
	}
	int k; cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> hole[i].start >> hole[i].pos >> hole[i].end >> hole[i].pos;
	}
	sort(hole, hole + k);
	for (int i = 0; i < k; ++i) {
		int h = hole[i].pos;
		for (int j = hole[i].start; j >= 0 ; --j) {
			if (startpos[j] >= a[j]) break;
			if (a[j] < h) {
				h = a[j];
				startpos[j] = h;
			}
			else {
				startpos[j] = h;
			}
		}
		h = hole[i].pos;
		for (int j = hole[i].start + 1; j < u; ++j) {
			if (startpos[j] >= a[j]) break;
			if (a[j] < h) {
				h = a[j];
				startpos[j] = h;
			}
			else {
				startpos[j] = h;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < u; ++i) {
		if (a[i] - startpos[i] < 0) startpos[i] = a[i];
		ans += (a[i] - startpos[i]);
	}
	cout << ans << '\n';
}