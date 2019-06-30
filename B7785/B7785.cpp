#include <iostream>
#include <memory.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string name, state;
	map<string, int>m;
	vector<string> p;
	for (int i = 0; i < n; ++i) {
		cin >> name >> state;
		if (state == "enter") m[name] = 1;
		else if (state == "leave") m[name] = -1;
	}
	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second == 1) p.push_back(i->first);
	}
	sort(p.begin(), p.end());
	for (int i = p.size() -1; i >= 0; --i) cout << p[i] << '\n';
}