#include <iostream>
#include <string>
#include <map>
using namespace std;
int p[100001];
int Rank[100001];
void init() {
	for (int i = 0; i <= 100000; ++i) {
		p[i] = i;
		Rank[i] = 1;
	}
}
int findparent(int x) {
	if (x == p[x]) return x;
	return p[x] = findparent(p[x]);
}
void merge(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (x == y) return;
	p[x] = y;
	int temp = Rank[x];
	Rank[x] += Rank[y];
	Rank[y] += temp;
}
void solve() {
	int n; cin >> n;
    string s1, s2;
    map<string, int> name;
	init();
    int cnt = 0;
	for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        int x, y;
        if (name.find(s2) != name.end()) {
            y = name[s2];
        }
        else {
            y = name[s2] = ++cnt;
        }
        if (name.find(s1) != name.end()) {
            x = name[s1];
        }
        else {
            x = name[s1] = ++cnt;
        }
        merge(x, y);
		x = findparent(x);
		cout << Rank[x] << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		solve();
	}
}
