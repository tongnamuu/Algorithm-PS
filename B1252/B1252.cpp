#include <iostream>
using namespace std;
int a[81];
int b[81];
int c[82];
int ans[82];
char input[82];
int getlen(char * str) {
	int len = 0;
	for (; str[len]; ++len);
	return len;
}
int main() {
	cin >> input;
	int len1 = getlen(input);
	for (int i = 0; i < len1; ++i) {
		a[len1 - i - 1] = input[i] - '0';
	}
	cin >> input;
	int len2 = getlen(input);
	for (int i = 0; i < len2; ++i) {
		b[len2 - i - 1] = input[i] - '0';
	}
	int len = len1 > len2 ? len1 : len2;
	for (int i = 0; i < len; ++i) {
		c[i + 1] = (a[i] + b[i] + c[i]) >= 2;
	}
	if (c[len] == 1) ans[len] = 1;
	else ans[len] = 0;
	for (int i = 0; i < len; ++i) {
		ans[i] = (a[i] ^ b[i]) ^ c[i];
	}
	bool find = false;
	for (int i = len; i >= 0; --i) {
		if (ans[i] == 1) find = true;
		if (find) cout << ans[i];
	}
	if (!find) cout << 0;
}