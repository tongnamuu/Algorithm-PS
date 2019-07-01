#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	string cmd;
	int S = 0, num;
	while (T--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> num;
			S |= (1 << num);
		}
		else if (cmd == "remove") {
			cin >> num;
			S &= ~(1 << num);
		}
		else if (cmd == "check") {
			cin >> num;
			int r = S & (1 << num);
			cout << (r > 0 ? 1 : 0) << '\n';
		}
		else if (cmd == "toggle") {
			cin >> num;
			S ^= (1 << num);
		}
		else if (cmd == "all") S = (1 << 21) - 1;
		else if (cmd == "empty") S = 0;
	}
}