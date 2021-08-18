#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int notPrime[1000001];
vector<long long> p;
void init() {
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i <= 1000000; ++i) {
        if (notPrime[i]) continue;
        p.push_back(i);
        for (int j = i + i; j <= 1000000; j += i) notPrime[j] = 1;
    }
}
vector<long long> solve(long long x) {
    vector<long long>res;
    for (long long num : p) {
        if (num > x) break;
        while (x > 0 && x%num == 0) {
            x /= num;
            res.push_back(num);
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    long long n; cin >> n;
    init();
    vector<long long> nums = solve(n);
    if (nums.size() <= 1) {
        cout << -1 << '\n';
        return 0;
    }
    if (nums.size() & 1) {
        for (int i = 0; i < nums.size() - 3; i += 2) {
            cout << nums[i] * nums[i + 1] << ' ';
        }
        cout << nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
    }
    else {
        for (int i = 0; i < nums.size(); i += 2) {
            cout << nums[i] * nums[i + 1] << ' ';
        }
    }
}
