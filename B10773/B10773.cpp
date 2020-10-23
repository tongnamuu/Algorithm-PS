#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    stack<int>s;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        if (num == 0) {
            if(!s.empty()) s.pop();
        }
        else {
            s.push(num);
        }
    }
    long long ans = 0;
    while (!s.empty()) {
        ans += s.top(); s.pop();
    }
    cout << ans;
}