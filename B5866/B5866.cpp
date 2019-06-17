#include <iostream>
using namespace std;
struct pos {
	int direction;
};
pos cow1[1000001], cow2[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int b, e; cin >> b >> e;
	int k = 0;
	for (int i = 0; i < b; ++i) {
		int d; char cmd;
		cin >> d >> cmd;
		for (int dist = 0; dist < d; ++dist) {
			if (cmd == 'L') cow1[k++].direction = -1;
			else cow1[k++].direction = 1;
		}
	}
	int k2 = 0;
	for (int i = 0; i < e; ++i) {
		int d; char cmd;
		cin >> d >> cmd;
		for (int dist = 0; dist < d; ++dist) {
			if (cmd == 'L') cow2[k2++].direction = -1;
			else cow2[k2++].direction = 1;
		}
	}
	int max = k > k2 ? k : k2;
	int x = 0, y = 0;
	int d1 = 0, d2 = 0;
	int ans = 0;
	for (int i = 1; i <= max; ++i) {
		if(d1<k)x += cow1[d1].direction;
		if(d2<k2)y += cow2[d2].direction;
		if (cow1[d1++].direction != cow2[d2++].direction&&x == y) ++ans;
	}
	cout << ans << '\n';
}