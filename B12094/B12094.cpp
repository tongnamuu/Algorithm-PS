#include <iostream>
#include <memory.h>
using namespace std;
#define END 10
struct Map {
	int a[21][21];
	Map() {
		memset(a, 0, sizeof(a));
	}
	void init() {
		memset(a, 0, sizeof(a));
	}
};
int n;
int ans = 0;
void move(const Map& prev, int cnt, int tempvalue) {
	ans = ans < tempvalue ? tempvalue : ans;
	if (cnt == END) return;
	if ((tempvalue << (END - cnt)) < ans) return;
	Map x;
	int temp;
	bool detect = false;
	temp = tempvalue;
	for (int j = 0; j < n; ++j) {
		int pos = -1;
		int nextpos = 0;
		while (pos < n&&nextpos < n) {
			if (prev.a[nextpos][j] == 0) ++nextpos;
			else if (pos != -1 && x.a[pos][j] == prev.a[nextpos][j]) {
				x.a[pos][j] <<= 1;
				temp = temp > x.a[pos][j] ? temp : x.a[pos][j];
				pos++; nextpos++;
				detect = true;
			}
			else {
				if (pos == -1 || x.a[pos][j]) ++pos;
				x.a[pos][j] = prev.a[nextpos][j];
				++nextpos;
			}
		}
	}
	if (!detect) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (x.a[i][j] == prev.a[i][j]) continue;
				detect = true;
			}
		}
	}
	if (detect) move(x, cnt + 1, temp);

	temp = tempvalue;
	x.init();
	detect = false;
	for (int j = 0; j < n; ++j) {
		int pos = n;
		int nextpos = n - 1;
		while (pos >= 0 && nextpos >= 0) {
			if (prev.a[nextpos][j] == 0) --nextpos;
			else if (pos != n && x.a[pos][j] == prev.a[nextpos][j]) {
				x.a[pos][j] <<= 1;
				temp = temp > x.a[pos][j] ? temp : x.a[pos][j];
				pos--, nextpos--;
				detect = true;
			}
			else {
				if (pos == n || x.a[pos][j]) --pos;
				x.a[pos][j] = prev.a[nextpos][j];
				nextpos--;
			}
		}
	}
	if (!detect) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (x.a[i][j] == prev.a[i][j]) continue;
				detect = true;
			}
		}
	}
	if (detect) move(x, cnt + 1, temp);

	temp = tempvalue;
	x.init();
	detect = false;
	for (int j = 0; j < n; ++j) {
		int pos = -1;
		int nextpos = 0;
		while (pos < n&&nextpos < n) {
			if (prev.a[j][nextpos] == 0) ++nextpos;
			else if (pos != -1 && x.a[j][pos] == prev.a[j][nextpos]) {
				x.a[j][pos] <<= 1;
				temp = temp > x.a[j][pos] ? temp : x.a[j][pos];
				++pos, ++nextpos;
				detect = true;
			}
			else {
				if (pos == -1 || x.a[j][pos]) ++pos;
				x.a[j][pos] = prev.a[j][nextpos];
				++nextpos;
			}
		}
	}
	if (!detect) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (x.a[i][j] == prev.a[i][j]) continue;
				detect = true;
			}
		}
	}
	if (detect) move(x, cnt + 1, temp);

	temp = tempvalue;
	x.init();
	detect = false;
	for (int j = 0; j < n; ++j) {
		int pos = n;
		int nextpos = n - 1;
		while (pos >= 0 && nextpos >= 0) {
			if (prev.a[j][nextpos] == 0) --nextpos;
			else if (pos != n && x.a[j][pos] == prev.a[j][nextpos]) {
				x.a[j][pos] <<= 1;
				temp = temp > x.a[j][pos] ? temp : x.a[j][pos];
				pos--, nextpos--;
				detect = true;
			}
			else {
				if (pos == n || x.a[j][pos]) --pos;
				x.a[j][pos] = prev.a[j][nextpos];
				--nextpos;
			}
		}
	}
	if (!detect) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (x.a[i][j] == prev.a[i][j]) continue;
				detect = true;
			}
		}
	}
	if (detect) move(x, cnt + 1, temp);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	Map x;
	int maxvalue = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> x.a[i][j];
			maxvalue = maxvalue > x.a[i][j] ? maxvalue : x.a[i][j];
		}
	}
	move(x, 0, maxvalue);
	cout << ans << '\n';
}