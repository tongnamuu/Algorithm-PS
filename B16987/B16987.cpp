#include <iostream>
using namespace std;
struct egg {
	int v, w;
};
int n;
egg a[8];
int ans = 0;
void go(int now, int cnt) {
	if (cnt > ans) ans = cnt;
	if (now == n) {
		return;
	}
	if (a[now].v <= 0) {
		go(now + 1, cnt);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i == now) continue;
		if (a[i].v <= 0) continue;
		int tempcnt = cnt;
		a[now].v -= a[i].w;
		a[i].v -= a[now].w;
		if (a[now].v <= 0) tempcnt++;
		if (a[i].v <= 0) tempcnt++;
		go(now + 1, tempcnt);
		a[now].v += a[i].w;
		a[i].v += a[now].w;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n; for (int i = 0; i < n; ++i) cin >> a[i].v >> a[i].w;
	go(0, 0);
	cout << ans << '\n';
}