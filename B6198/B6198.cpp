#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    stack<int>s;
    long long ans = 0;
    for (int i = 0, height; i < n; ++i) {
        cin >> height;
        while (!s.empty() && s.top() <= height) {
            s.pop();
        }
        ans += s.size();
        s.push(height);
    }
    cout << ans;
}
