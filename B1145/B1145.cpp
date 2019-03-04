#include <iostream>
using namespace std;
int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
bool next_permutation(int a[], int n) {
	int index = n - 1;
	while (index >= 1 && a[index - 1] >= a[index]) --index;
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
		--ind;
		++index;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a[5]; for (int i = 0; i < 5; ++i) cin >> a[i];
	int d[5] = { 0,0,1,1,1 };
	int ans = 1000001;
	do {
		int x = -1, y = -1, temp = -1;
		for (int i = 0; i < 5; ++i) {
			if (d[i]) {
				if (temp == -1) temp = a[i];
				else if (x == -1) x = a[i];
				else if (y == -1) y = a[i];
			}
		}
		temp = temp * x / gcd(temp, x);
		temp = temp * y / gcd(temp, y);
		if (temp < ans) ans = temp;
	} while (next_permutation(d, 5));
	cout << ans << '\n';
}