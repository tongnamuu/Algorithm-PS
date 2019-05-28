#include <iostream>
#include <algorithm>
using namespace std;
struct keyboard {
	int id;
	int time;
	char ch;
	bool operator<(const keyboard& a) const {
		if (a.time != this->time) return this->time < a.time;
		else return this->id < a.id;
	}
};
keyboard k[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> k[i].id >> k[i].time >> k[i].ch;
	}
	sort(k, k + m);
	for (int i = 0; i < m; ++i) {
		cout << k[i].ch;
	}
}