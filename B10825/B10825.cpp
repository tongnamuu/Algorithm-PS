#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct info {
	string name;
	int a, b, c;
	bool operator<(const info p) const {
		if (this->a != p.a) return this->a > p.a;
		else {
			if (this->b != p.b) return this->b < p.b;
			else {
				if (this->c != p.c) return this->c > p.c;
				else return this->name < p.name;
			}
		}
	}
};
info person[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> person[i].name >> person[i].a >> person[i].b >> person[i].c;
	sort(person, person + n);
	for (int i = 0; i < n; ++i) cout << person[i].name << '\n';
}