#include <iostream>
using namespace std;
int n, m;
int a[10];
void go(int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; ++i) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; ++i) {
		a[index] = i;
		go(index + 1, i);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		a[0] = i;
		go(1, i);
	}
}