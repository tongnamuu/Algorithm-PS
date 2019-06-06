#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int a[11];
int sign[11][11];
bool findans = false;
bool check(int index) {
	int sum = 0;
	for (int i = index; i >= 0; --i) {
		sum += a[i];
		if (sum >= 0 && sign[i][index] < 0) return false;
		else if (sum <= 0 && sign[i][index] > 0) return false;
		else if (sum != 0 && sign[i][index] == 0) return false;
	}
	return true;
}
void go(int index) {
	if (findans) return;
	if (index == n) {
		for (int i = 0; i < n; ++i) cout << a[i] << ' ';
		cout << '\n';
		findans = true;
		return;
	}
	if (sign[index][index] == 0) {
		a[index] = 0;
		go(index + 1);
	}
	else {
		for (int i = 1; i <= 10; ++i) {
			a[index] = i*sign[index][index];
			if (check(index)&&!findans) {
				go(index + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n; cin >> s;
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (s[k] == '+') sign[i][j] = 1;
			else if(s[k]=='-') sign[i][j] = -1;
			else if (s[k] == '0') sign[i][j] = 0;
			++k;
		}
	}
	go(0);
}