#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; cin >> s;
	int len = s.length();
	int index = 0;
	int cnt = 0;
	for (int i = 0; s[i];) {
		string temp;
		if(i<=len-2) temp = s.substr(i, 2);
		if (temp == "dz") {
			if (i + 2 < len && s[i + 2] == '=') {
				++cnt;
				i += 3;
			}
			else {
				cnt += 2;
				i += 2;
			}
		}
		else if (temp == "c=") {
			++cnt; i += 2;
		}
		else if (temp == "c-") {
			++cnt; i += 2;
		}
		else if (temp == "d-") {
			++cnt; i += 2;
		}
		else if (temp == "lj") {
			++cnt; i += 2;
		}
		else if (temp == "nj") {
			++cnt; i += 2;
		}
		else if (temp == "s=") {
			++cnt; i += 2;
		}
		else if (temp == "z=") {
			++cnt; i += 2;
		}
		else {
			++i;
			++cnt;
		}
	}
	cout << cnt << '\n';
}