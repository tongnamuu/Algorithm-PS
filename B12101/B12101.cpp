#include <iostream>
using namespace std;
int a[11];
int n, k;
int x;
void go(int index, int sum) {
	if (sum > n) return;
	if (sum == n) {
		++x;
		if (x == k) {
			for (int i = 0; i < index; ++i) {
				cout << a[i];
				if (i < index - 1) cout << '+';
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		a[index] = i;
		go(index + 1, sum + i);
	}
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 3; ++i) {
		a[0] = i;
		go(1, i);
	}
	if (x < k) cout << -1 << '\n';
}