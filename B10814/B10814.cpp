#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct info {
	string name;
	int age;
	int turn;
	bool operator<(const info &a) const {
		if (this->age == a.age) return this->turn < a.turn;
		else return this->age < a.age;
	}
};
info a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		string name;
		cin >> num >> name;
		a[i].age = num;
		a[i].name = name;
		a[i].turn = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) cout << a[i].age << ' ' << a[i].name << '\n';
}