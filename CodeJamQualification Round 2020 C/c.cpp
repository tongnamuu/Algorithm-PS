#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int check[1441];
char ans[1001];
struct abcde {
	int s, e, index;
};
abcde a[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(check, 0, sizeof(check));
		int n; cin >> n;
		ans[n] = '\0';
		bool r = true;
		for (int i = 0; i < n; ++i) {
			int s, e; cin >> s >> e;
			a[i].s = s; a[i].e = e; a[i].index = i;
			for (int time = s; time < e; ++time) {
				check[time]++;
				if (check[i] > 2)r = false;
			}
		}
		sort(a, a + n, [](const abcde& u, const abcde& v) {
			if (u.s == v.s) return u.e < v.e;
			return u.s < v.s;
		});
		cout << "Case #" << tc << ": ";
		if (!r) cout << "IMPOSSIBLE\n";
		else {
			int je = a[0].e, ce = a[1].e;
			int index = 1;
			ans[a[0].index] = 'J';
			ans[a[1].index] = 'C';
			for (int i = 2; i < n; ++i) {
				if (a[i].s >= je) {
					je = a[i].e;
					ans[a[i].index] = 'J';
				}
				else if (a[i].s >= ce) {
					ce = a[i].e;
					ans[a[i].index] = 'C';
				}
			}
			cout << ans << '\n';
		}
	}
}