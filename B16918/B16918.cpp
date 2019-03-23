#include <iostream>
using namespace std;
int n;
long long ans = 0;
void go(int index, int cnt, long long temp, int a[]) {
	temp += a[index + 1] * a[index - 1];
	if (cnt == 3) {
		if (temp > ans)
			ans = temp;
		return;
	}
	int j = 0;
	int b[10];
	for (int i = 0; i < index; i++) {
		b[j++] = a[i];
	}
	for (int i = index + 1; i < cnt; i++) {
		b[j++] = a[i];
	}
	--cnt;
	for (int i = 1; i < cnt - 1; i++) {
		go(i, cnt, temp, b);
	}
}
int main() {
	cin >> n;
	int a[10];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < n - 1; ++i) {
		go(i, n, 0, a);
	}
	cout << ans << '\n';
}