#include <iostream>
#include <string>
using namespace std;
char a[81];
int n;
bool completed = false;
bool ok() {
    string temp = string(a);
    for (int s = 0; s < temp.length(); ++s) {
        for (int e = s + 1; e < temp.length(); ++e) {
            int len = e - s + 1;
            string sub = temp.substr(s, len);
            if (sub.length() == len && sub == temp.substr(e + 1, len)) return false;
        }
    }
    return true;
}
void make_number(int idx, int before) {
    if (completed) return;
    a[idx] = '\0';
    if (!ok()) return;
    if (idx == n) {
        a[n] = '\0';
        cout << a;
        completed = true;
        return;
    }
    for (int i = 1; i <= 3; ++i) {
        if (i == before) continue;
        a[idx] = i + '0';
        make_number(idx + 1, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    make_number(0, -1);
}
