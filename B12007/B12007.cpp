#include <iostream>
#include<algorithm>
using namespace std;
pair<int, int> a[50001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int x1 = 400001, x2 = 400001, x3 = 0, x4 = 0;
	int y1 = 400001, y2 = 400001, y3 = 0, y4 = 0;
	for (int i = 0, g, s; i < n; ++i) {
		cin >> g >> s;
		if (g < x1) {
			x2 = x1;
			x1 = g;
		}
		else if (g < x2) {
			x2 = g;
		}
		
		if (g > x3) {
			x4 = x3;
			x3 = g;
		}
		else if (g > x4) {
			x4 = g;
		}

		if (s < y1) {
			y2 = y1;
			y1 = s;
		}
		else if (s < y2) {
			y2 = s;
		}

		if (s > y3) {
			y4 = y3;
			y3 = s;
		}
		else if (s > y4) {
			y4 = s;
		}
		a[i].first = g;
		a[i].second = s;
	}
	int ans = (x3 - x1)*(y3 - y1);
	for (int i = 0; i < n; ++i) {
		int gmin = x1;
		if (a[i].first == gmin) {
			gmin = x2;
		}
		int gmax = x3;
		if (a[i].first == gmax) {
			gmax = x4;
		}
		int smin = y1;
		if (a[i].second == smin) {
			smin = y2;
		}
		int smax = y3;
		if (a[i].second == smax) {
			smax = y4;
		}
		if (ans > (gmax - gmin)*(smax - smin))
			ans = (gmax - gmin)*(smax - smin);
	}
	cout << ans << '\n';
}