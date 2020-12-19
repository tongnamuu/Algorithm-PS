#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> get_array(int n) {
    if (n == 0) return vector<int>(1);
    vector<int>res;
    while (n) {
        res.push_back(n % 10);
        n /= 10;
    }
    sort(res.begin(), res.end());
    return res;
}
int get_value(vector<int>& vec) {
    int ans = 0;
    if (vec[0] == 0) return -1;
    for (int i = 0; i < vec.size(); ++i) {
        ans *= 10;
        ans += vec[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int a, b; cin >> a >> b;
    vector<int> vec = get_array(a);
    int ans = -1;
    do {
        int val = get_value(vec);
        if (val <= b) {
            ans = max(ans, val);
        }
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans;
}
