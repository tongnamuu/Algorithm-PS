#include <iostream>
using namespace std;
int a[1000001];
int d[1000001];
int p[1000001];
int pn;
int lower_bound(int * arr, int size, int val) {
	int start = 0, end = size - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= val) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	d[0] = 1;
	p[pn++] = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] > p[pn - 1]) {
			p[pn++] = a[i];
			d[i] = pn;
		}
		else if (a[i] < p[pn - 1]) {
			int index = lower_bound(p, pn, a[i]);
			p[index] = a[i];
			d[i] = index + 1;
		}
	}
	cout << pn << '\n';
	int cur = pn;
	for (int i = n - 1; i >= 0; --i) {
		if (cur == 0) break;
		if (d[i] == cur) {
			p[cur - 1] = a[i];
			cur--;
		}
	}
	for (int i = 0; i < pn; ++i) cout << p[i] << ' ';
}