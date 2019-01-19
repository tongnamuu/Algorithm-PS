#include <iostream>
using namespace std;
void swap(int &a, int &b) {
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
	swap(a[index - 1], a[ind]);
	ind = n - 1;
	while (index < ind) {
		swap(a[index], a[ind]);
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
	int k;
	cin >> k;
	if (k == 1) {
		int cnt;
		cin >> cnt;
		int a[20];
		for (int i = 0; i < n; ++i) a[i] = i + 1;
		while (--cnt&&next_permutation(a, n)) {}
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';		
	}
	else if (k == 2) {
		int a[20];
		int b[20];
		for (int i = 0; i < n; ++i) {
			a[i] = i + 1; cin >> b[i];
		}
		bool go = true;
		int cnt = 0;
		do {
			go = true;
			for (int i = 0; i < n; ++i) {
				if (a[i] != b[i]) {
					go = false;
					break;
				}
			}
			cnt++;
		} while (!go && next_permutation(a, n));
		cout << cnt << '\n';
	}
}