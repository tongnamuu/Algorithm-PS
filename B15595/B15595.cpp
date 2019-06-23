#include <iostream>
#include <string>
#include <map>
using namespace std;
int num, result, memory, time, lang, codelen;
string id;
int main() {
	int n; cin >> n;
	map<string, int>m;
	map<string, int>submit;
	for (int i = 0; i < n; ++i) {
		cin >> num >> id >> result >> memory >> time >> lang >> codelen;
		if (id == "megalusion") continue;
		if (m[id] > 0) continue;
		if (result == 4) m[id] = 1;
		else submit[id] += 1;
	}
	int ans = 0;
	int total = 0;
	for (auto i = m.begin(); i != m.end(); ++i) {
		if (i->second > 0) {
			++ans;
			total += submit[i->first];
			++total;
		}
	}
	cout << fixed;
	cout.precision(10);
	if (ans == 0) cout << 0 << '\n';
	else cout << (double)ans * 100 / total << '\n';
}