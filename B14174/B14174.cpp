#include <iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int n;
	cin >> n;
	char a[11];
	int d[26] = { 0, };
	for (int i = 0; i < n; ++i) {
		cin >> a;
		int da[26] = { 0, };
		int db[26] = { 0, };
		for (int j = 0; a[j]; ++j) {
			++da[a[j] - 'a'];
		}
		cin >> a;
		for (int j = 0; a[j]; ++j) {
			++db[a[j] - 'a'];
		}
		for (int j = 0; j < 26; ++j) {
			d[j] += max( da[j], db[j] );
		}
	}
	for (int i = 0; i < 26; ++i) cout << d[i] << '\n';
}