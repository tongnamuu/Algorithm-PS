#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	cin.ignore();
	while (T--) {
		string s;
		getline(cin, s);
		string temp;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == ' ') {
				reverse(temp.begin(), temp.end());
				cout << temp << ' ';
				temp = "";
				continue;
			}
			temp += s[i];
		}
		reverse(temp.begin(), temp.end());
		cout << temp << '\n';
	}
}