#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p[1001];
void compress(vector<pair<int, int>>& a) {
    int n = a.size();
    vector<int>temp(n);
    for (int i = 0; i < n; ++i) {
        temp[i] = a[i].first;
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (int i = 0; i < n; ++i) {
        a[i].first = lower_bound(temp.begin(), temp.end(), a[i].first) - temp.begin();
    }
    temp.resize(n);
    for (int i = 0; i < n; ++i) {
        temp[i] = a[i].second;
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (int i = 0; i < n; ++i) {
        a[i].second = lower_bound(temp.begin(), temp.end(), a[i].second) - temp.begin();
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    compress(a);
    for (int i = 0; i < n; ++i) {
        for (int j = a[i].first; j < 1000; ++j) {
            p[j].push_back(a[i].second);
        }
    }
    int cnt[4];
    int ans = 2147483647;
    for (int i = 0; i < 1000; ++i) sort(p[i].begin(), p[i].end());
    for (int y = 0; y < 1000; ++y) {
        for (int x = 0; x < 1000; ++x) {
            cnt[0] = upper_bound(p[x].begin(), p[x].end(), y) - p[x].begin();
            cnt[1] = p[x].size() - cnt[0];
            cnt[2] = upper_bound(p[999].begin(), p[999].end(), y) - p[999].begin() - cnt[0];
            cnt[3] = n - cnt[0] - cnt[1] - cnt[2];
            sort(cnt, cnt + 4);
            ans = ans > cnt[3] ? cnt[3] : ans;
        }
    }
    cout << ans;
}
