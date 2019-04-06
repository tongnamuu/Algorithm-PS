#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct data1 {
	string str;
	int len;
	bool operator<(const data1& a) const {
		if (this->len == a.len) return this->str < a.str;
		else return this->len < a.len;
	}
};
data1 a[20001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].str;
		a[i].len = a[i].str.length();
	}
	sort(a, a + n);
	string prev = a[0].str;
	cout << prev << '\n';
	for (int i = 1; i < n; ++i) {
		if (a[i].str == prev) continue;
		cout << a[i].str << '\n';
		prev = a[i].str;
	}
}