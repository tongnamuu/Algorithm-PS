#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	map<string, int>map;
	string name;
	vector<string>p;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		map[name]++;
	}
	for (int i = 0; i < m; ++i) {
		cin >> name;
		map[name]++;
	}
	for (auto i = map.begin(); i != map.end(); ++i) {
		if (i->second == 2) p.push_back(i->first);
	}
	sort(p.begin(), p.end());
	cout << p.size() << '\n';
	for (auto& person : p) cout << person << '\n';
}