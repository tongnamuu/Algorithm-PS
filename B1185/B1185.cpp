#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10001];
struct pos {
	int from, to, weight;
	bool operator<(const pos& a) const {
		return this->weight < a.weight;
	}
};
struct Unionfind {
	int p[100001];
	int findparent(int x) {
		if (x == p[x]) return x;
		else return p[x] = findparent(p[x]);
	}
	void merge(int x, int y) {
		x = findparent(x), y = findparent(y);
		if (x != y) p[x] = y;
	}
	Unionfind() {
		for (int i = 0; i <= 10000; ++i) {
			p[i] = i;
		}
	}
};
Unionfind u;
pos b[100001];
int pn = 0;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int p; cin >> p;
	int start = 2147483647;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (start > a[i]) {
			start = a[i];
		}
	}
	for (int i = 0; i < p; ++i) {
		cin >> b[i].from >> b[i].to >> b[i].weight;
		b[i].weight *= 2;
		b[i].weight +=a[b[i].to];
		b[i].weight +=a[b[i].from];
	}
	sort(b, b + p);
	int ans = start;
	for (int i = 0; i < p; ++i) {
		pos temp = b[i];
		int x = u.findparent(temp.from);
		int y = u.findparent(temp.to);
		if (x != y) {
			u.merge(temp.from, temp.to);
			ans += temp.weight;
		}
	}
	cout << ans << '\n';
}