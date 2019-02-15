#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long a[101];
long long ans[101];
int pn;
bool ansfind = false;
void go(int cnt,int index) {
	if (ansfind) return;
	if (cnt == n) {
		ansfind = true;
		for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	if (a[index] % 3 == 0) {
		for (int i = 0; i <= index; ++i) {
			if (a[i] == a[index] / 3) {
				ans[pn++] = a[i];
				go(cnt+1,i);
				--pn;
			}
		}
	}
	for (int i = index; i < n; ++i) {
		if (a[i] == 2 * a[index]) {
			ans[pn++] = a[i];
			go(cnt + 1, i);
			--pn;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	pn = 0;
	for (int i = 0; i < n; ++i) {
		ans[pn++] = a[i];
		go(1, i);
		--pn;
	}
}