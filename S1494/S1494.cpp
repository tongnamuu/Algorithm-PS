#include <iostream>
using namespace std;
bool next_permutation(int a[], int n) {
	int index = n - 1;
	while (index>=1 && a[index - 1] >= a[index]) --index;
	if (index == 0) return false;
	int ind = n - 1;
	while (a[index - 1] >= a[ind]) --ind;
	int temp = a[ind];
	a[ind] = a[index - 1];
	a[index - 1] = temp;
	ind = n - 1;
	while (index < ind) {
		temp = a[ind];
		a[ind] = a[index];
		a[index] = temp;
		++index;
		--ind;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case){
		int n; cin >> n;
		pair<int, int> pos[21];
		for (int i = 0; i < n; ++i) {
			cin >> pos[i].first >> pos[i].second;
		}
		long long ans = (long long)4*100000*100000*11;
		int d[20];
		for (int i = 0; i < n / 2; ++i) d[i] = 0;
		for (int i = n / 2; i < n; ++i) d[i] = 1;
		do {
			if (d[0] != 0) break;
			long long tempx = 0;
			long long tempy = 0;
			for (int i = 0; i < n; ++i) {
				if (d[i]) {
					tempx += pos[i].first;
					tempy += pos[i].second;
				}
				else {
					tempx -= pos[i].first;
					tempy -= pos[i].second;
				}
			}
			long long temp = tempx * tempx + tempy * tempy;
			if (ans > temp) ans = temp;
		} while (next_permutation(d, n));
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}