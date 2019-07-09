#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a[10];
void go(int index) {
	if (index == m) {
		for (int i = 0; i < m; ++i) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i) {
		a[index] = i;
		go(index+1);
	}
}
int main() {
	cin >> n >> m;
	go(0);
}