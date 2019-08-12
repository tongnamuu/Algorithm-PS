#include <iostream>
using namespace std;
struct info {
	int data;
	int index;
	int cnt;
};
info a[500001];
info b[500001];
void sort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(start, mid); sort(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i].data < a[j].data) {
			a[j].cnt -= (mid + 1 - i);
			b[k++] = a[j++];
		}
		else b[k++] = a[i++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= end) b[k++] = a[j++];
	for (int s = start; s <= end; ++s) {
		a[s] = b[s - start];
	}
}
void sort2(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort2(start, mid); sort2(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i].index > a[j].index) b[k++] = a[j++];
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
		cin >> a[i].data;
		a[i].index = i;
		a[i].cnt = i + 1;
	}
	sort(0, n - 1); sort2(0, n - 1);
	for (int i = 0; i < n; ++i) cout << a[i].cnt << '\n';
}