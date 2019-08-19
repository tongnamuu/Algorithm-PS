#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int choose[4];
int a[11];
bool check[11];
int n, k;
set<string>s;
string numtostring(int num) {
	if (num == 0) return "0";
	string temp;
	while (num) {
		temp += num % 10 + '0';
		num /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
void solve() {
	string hubo;
	for (int i = 0; i < k; ++i) {
		hubo += numtostring(choose[i]);
	}
	s.insert(hubo);
}
void go(int cnt) {
	if (cnt == k) {
		solve();
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!check[i]) {
			check[i] = true;
			choose[cnt] = a[i];
			go(cnt + 1);
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i) {
		check[i] = true;
		choose[0] = a[i];
		go(1);
		check[i] = false;
	}
	cout << s.size() << '\n';
}