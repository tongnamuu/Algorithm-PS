#include <iostream>
using namespace std;
int a[500001];
int b[500001];
long long ans;
void sort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(start, mid), sort(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] > a[j]) {
			b[k++] = a[j++];
			ans += mid - i + 1;
		}
		else {
			b[k++] = a[i++];
		}
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
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(0, n - 1);
	cout << ans << '\n';
}