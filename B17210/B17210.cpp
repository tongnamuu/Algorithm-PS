#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n; cin >> n;
	int s; cin >> s;
	if (n >= 6) {
		cout << "Love is open door";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		s ^= 1;
		cout << s << '\n';
	}
}
