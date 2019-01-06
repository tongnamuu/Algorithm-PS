#include <iostream>
using namespace std;
void swap1(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
	return;
}
bool next_permutation(int a[], int n) {
	int index = n - 1;
	while (index >= 1 && a[index - 1] >= a[index]) --index;
	if (index == 0) return false;
	int ind = n - 1;
	while (a[ind] <= a[index - 1]) ind--;
	swap1(a[ind], a[index - 1]);
	ind = n - 1;
	while (index < ind) {
		swap1(a[index], a[ind]);
		++index;
		--ind;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[10001];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (next_permutation(a, n)) {
		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	else cout << -1 << '\n';
}