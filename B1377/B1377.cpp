#include <iostream>
using namespace std;
pair<int, int>b[500001];
pair<int, int>a[500001];
void sort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(start, mid); sort(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] > a[j]) b[k++] = a[j++];
		else b[k++] = a[i++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= end) b[k++] = a[j++];
	for (int s = start; s <= end; ++s) {
		a[s] = b[s - start];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(0, n - 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i].second - i > ans) ans = a[i].second - i;
	}
	cout << ans + 1 << '\n';
}