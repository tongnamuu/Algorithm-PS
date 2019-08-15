#include <iostream>
using namespace std;
char a[16][16];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 5; ++i) cin >> a[i];
	for (int j = 0; j < 16; ++j) {
		for (int i = 0; i < 5; ++i) {
			if (a[i][j]) cout << a[i][j];
		}
	}
}