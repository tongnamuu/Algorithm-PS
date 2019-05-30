#include <iostream>
#include <vector>
using namespace std;
struct drinkinfo {
	int personid;
	int milkid;
	int time;
};
struct sickinfo {
	int person;
	int time;
};
int n, m, D, S;
drinkinfo dinfo[1001];
sickinfo sinfo[1001];
int peopledrink(int milk) {
	bool drinkmilk[51] = { false, };
	for (int i = 0; i < D; ++i) {
		if (dinfo[i].milkid == milk) drinkmilk[dinfo[i].personid] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= 50; ++i) {
		cnt += drinkmilk[i];
	}
	return cnt;
}
bool beforedrink(sickinfo s, int milk) {
	for (int i = 0; i < D; ++i) {
		if (dinfo[i].personid == s.person&&dinfo[i].milkid == milk && dinfo[i].time < s.time) return true;
	}
	return false;
}
bool Badmilk(int milk) {
	for (int i = 0; i < S; ++i) {
		if (!beforedrink(sinfo[i], milk)) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> n >> m >> D >> S;
	for (int i = 0, person, milkid, time; i < D; ++i) {
		cin >> person >> milkid >> time;
		dinfo[i] = { person,milkid,time };
	}
	for (int i = 0, person, t; i < S; ++i) {
		cin >> person >> t;
		sinfo[i] = { person,t };
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (Badmilk(i)) {
			int cnt = peopledrink(i);
			if (cnt > ans) ans = cnt;
		}
	}
	cout << ans << '\n';
}