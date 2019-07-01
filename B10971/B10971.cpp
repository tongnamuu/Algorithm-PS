#include <iostream>
using namespace std;
bool next_permutation(int a[], int n) {
	int index = n - 1;
	while (index >= 1 && a[index - 1] >= a[index]) --index;
	if (index == 0) return false;
	int ind = n - 1;
	while (a[index - 1] >= a[ind]) --ind;
	int temp = a[index - 1];
	a[index - 1] = a[ind];
	a[ind] = temp;
	ind = n - 1;
	while (index < ind) {
		temp = a[index];
		a[index] = a[ind];
		a[ind] = temp;
		++index, --ind;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[11][11];
	for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) cin >> a[i][j];
	int d[] = { 0,1,2,3,4,5,6,7,8,9 };
	int ans = 2147483647;
	do {
		if (d[0] != 0) break;
		bool canrun = true;
		int w = 0;
		for (int i = 0; i + 1 < n; ++i) {
			if (a[d[i]][d[i+1]] == 0) {
				canrun = false;
				break;
			}
			w += a[d[i]][d[i + 1]];
		}
		if (canrun && a[d[n - 1]][0] > 0) {
			if (w + a[d[n - 1]][0]< ans) ans = w + a[d[n - 1]][0];
		}

	} while (next_permutation(d, n));
	cout << ans << '\n';
}