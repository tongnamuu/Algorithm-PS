#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct cow {
	int num;
	string id;
	bool operator<(const cow& a) const {
		return this->num < a.num;
	}
};
cow a[101];
int temp[101];
int d[101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		a[i].num = i;
		cin >> d[i];
	}
	for (int k= 0; k < 3; ++k) {
		for (int i = 1; i <= n; ++i) {
			temp[d[i]] = a[i].num;
		}
		for (int i = 1; i <= n; ++i) {
			a[i].num = temp[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].id;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) cout << a[i].id << '\n';
}