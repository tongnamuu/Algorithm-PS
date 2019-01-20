#include <iostream>
using namespace std;
void merge(int a[], int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = 0;
	int b[100001];
	while (i <= mid && j <= end) {
		if (a[i] < a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= end) b[k++] = a[j++];
	for (int s = start; s <= end; ++s) a[s] = b[s - start];
}
void sort(int a[], int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(a, start, mid);
	sort(a, mid + 1, end);
	merge(a, start, end);
}
bool find(int a[], int start, int end, int key) {
	int l = start;
	int r = end;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == key) return true;
		else if (key > a[mid]) l = mid + 1;
		else if (key < a[mid]) r = mid - 1;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[100001];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, 0, n - 1);
	int m;
	cin >> m;
	int key;
	while (m--) {
		cin >> key;
		if (find(a, 0, n - 1, key)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}