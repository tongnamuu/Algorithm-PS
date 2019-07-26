#include <iostream>
using namespace std;
int a[1000001];
int d[1000001];
int pn;
int lower_bound(int a[], int n, int val) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] >= val) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	d[pn++] = a[0];
	for (int i = 1; i < n; ++i) {
		if (d[pn - 1] < a[i]) {
			d[pn++] = a[i];
		}
		else {
			int index = lower_bound(d, pn, a[i]);
			d[index] = a[i];
		}
	}
	cout << pn << '\n';
}