#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int commands[64];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    char cmd[10];
    while (1) {
        for (int i = 0; i < 32; ++i) {
            cin >> cmd;
            if (cin.eof() == true) return 0;
            int val = 0;
            for (int j = 0; j < 8; ++j) {
                val <<= 1;
                val += cmd[j] - '0';
            }
            commands[i] = val;
        }

        unsigned int cur = 0, idx = 0;
        while (1) {
            int command = (commands[idx] >> 5);
            int val = (commands[idx] & 31);
            ++idx;
            idx &= 31;
            if (command == 0) {
                commands[val] = cur;
            }
            else if (command == 1) {
                cur = commands[val];
            }
            else if (command == 2) {
                if (cur == 0) idx = val;
            }
            else if (command == 3) {
            }
            else if (command == 4) {
                cur -= 1;
                cur &= 255;
            }
            else if (command == 5) {
                cur += 1;
                cur &= 255;
            }
            else if (command == 6) {
                idx = val;
            }
            else if (command == 7) {
                break;
            }
        }
        string ans;
        for (int i = 7; i >= 0; --i) {
            if (cur&(1 << i)) {
                ans += '1';
            }
            else {
                ans += '0';
            }
        }
        cout << ans << '\n';
    }
}
