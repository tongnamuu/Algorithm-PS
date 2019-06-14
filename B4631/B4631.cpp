#include <iostream>
#include <string>
using namespace std;
string name[16];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 0;
	while (true) {
		++T;
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n / 2; ++i) {
			cin >> name[i];
			cin >> name[n - i - 1];
		}
		if (n & 1) cin >> name[n / 2];
		cout << "SET" << ' ' << T << '\n';
		for (int i = 0; i < n; ++i) cout << name[i] << '\n';
	}
}