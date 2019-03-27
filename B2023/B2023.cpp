#include <iostream>
using namespace std;
int n;
bool check(int num) {
	for (int i = 2; i*i <= num; ++i) {
		if (num%i == 0) return false;
	}
	return true;
}
void go(int now, int len) {
	if (len == n) {
		cout << now << '\n';
		return;
	}
	for (int i = 1; i <= 9; i+=2) {
		if (check(now * 10 + i)) {
			go(now * 10 + i, len + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	go(2,1);
	go(3,1);
	go(5,1);
	go(7,1);
}