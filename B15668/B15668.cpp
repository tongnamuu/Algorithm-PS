#include <iostream>
using namespace std;
long long n;
bool findans;
bool check(long long num, int visit) {
	while (num) {
		if (visit & (1<<(num%10))) return false;
		visit |= (1 << (num % 10));
		num /= 10;
	}
	return true;
}
void go(long long a, int visit) {
	if (findans) return;
	if (a >= n) return;
	if (a > 0 && n - a > 0 && check(n-a, visit)) {
		cout << a << " + " << n - a;
		findans = true;
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (!(visit&(1 << i))) {
			visit |= (1 << i);
			go(a * 10 + i, visit);
			visit ^= (1 << i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	go(0, 0);
	if (!findans) cout << -1 << '\n';
}