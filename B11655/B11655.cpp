#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; getline(cin, s);
	for (int i = 0; s[i]; ++i) {
		if (s[i] >= 'a'&&s[i] <= 'z') {
			int x = s[i] - 'a';
			x += 13; x %= 26;
			cout << (char)(x + 'a');
		}
		else if (s[i] >= 'A'&&s[i] <= 'Z') {
			int x = s[i] - 'A';
			x += 13; x %= 26;
			cout << (char)(x + 'A');
		}
		else cout << s[i];
	}
}