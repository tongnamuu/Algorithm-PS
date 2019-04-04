#include <iostream>
#include <string>
using namespace std;
int a[21][21];
int n;
void moveup() {
	for (int k = 0; k < n; ++k) {
		int temp[21] = { 0, };
		int index = 0;
		for (int i = 0; i < n;) {
			if (a[i][k] == 0) {
				++i;
				continue;
			}
			bool indexchange = false;
			for (int j = i + 1; j < n; ++j) {
				if (a[i][k] == a[j][k]) {
					a[i][k] *= 2;
					temp[index++] = a[i][k];
					a[j][k] = 0;
					i = j + 1;
					indexchange = true;
					break;
				}
				else if (a[j][k] > 0 && a[i][k] != a[j][k]) {
					temp[index++] = a[i][k];
					i = j;
					indexchange = true;
					break;
				}
			}
			if (!indexchange) {
				temp[index++] = a[i][k];
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			a[i][k] = temp[i];
		}
	}
}
void movedown() {
	for (int k = 0; k < n; ++k) {
		int temp[21] = { 0, };
		int index = n-1;
		for (int i = n-1; i >=0;) {
			if (a[i][k] == 0) {
				--i;
				continue;
			}
			bool indexchange = false;
			for (int j = i - 1; j >=0; --j) {
				if (a[i][k] == a[j][k]) {
					a[i][k] *= 2;
					temp[index--] = a[i][k];
					a[j][k] = 0;
					i = j - 1;
					indexchange = true;
					break;
				}
				else if (a[j][k] > 0 && a[i][k] != a[j][k]) {
					temp[index--] = a[i][k];
					i = j;
					indexchange = true;
					break;
				}
			}
			if (!indexchange) {
				temp[index--] = a[i][k];
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			a[i][k] = temp[i];
		}
	}
}
void moveright() {
	for (int k = 0; k < n; ++k) {
		int temp[21] = { 0, };
		int index = n - 1;
		for (int i = n - 1; i >= 0;) {
			if (a[k][i] == 0) {
				--i;
				continue;
			}
			bool indexchange = false;
			for (int j = i - 1; j >= 0; --j) {
				if (a[k][i] == a[k][j]) {
					a[k][i] *= 2;
					temp[index--] = a[k][i];
					a[k][j] = 0;
					i = j - 1;
					indexchange = true;
					break;
				}
				else if (a[k][j] > 0 && a[k][i] != a[k][j]) {
					temp[index--] = a[k][i];
					i = j;
					indexchange = true;
					break;
				}
			}
			if (!indexchange) {
				temp[index--] = a[k][i];
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			a[k][i] = temp[i];
		}
	}
}
void moveleft() {
	for (int k = 0; k < n; ++k) {
		int temp[21] = { 0, };
		int index = 0;
		for (int i = 0; i < n;) {
			if (a[k][i] == 0) {
				++i;
				continue;
			}
			bool indexchange = false;
			for (int j = i + 1; j < n; ++j) {
				if (a[k][i] == a[k][j]) {
					a[k][i] *= 2;
					temp[index++] = a[k][i];
					a[k][j] = 0;
					i = j + 1;
					indexchange = true;
					break;
				}
				else if (a[k][j] > 0 && a[k][i] != a[k][j]) {
					temp[index++] = a[k][i];
					i = j;
					indexchange = true;
					break;
				}
			}
			if (!indexchange) {
				temp[index++] = a[k][i];
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			a[k][i] = temp[i];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		string cmd; cin >> cmd;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)cin >> a[i][j];
		if (cmd == "up") moveup();
		else if (cmd == "down") movedown();
		else if (cmd == "left") moveleft();
		else if (cmd == "right") moveright();
		cout << '#' << test_case << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
	}
}