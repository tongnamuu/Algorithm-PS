#include <iostream>
#include <string>
using namespace std;
char a[1000001];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    string s; cin >> s;
    int size = 0;
    int len = s.length();
    bool ans = true;
    int i = 0;
    if (s[0] == 'A')
        ans = false;
    else
    {
        while (i < len)
        {
            if (s[i] == 'P')
            {
                a[size++] = 'P';
                i++;
            }
            else if (s[i] == 'A'&&s[i + 1] == 'P')
            {
                if (size - 2 >= 0)
                {
                    if (a[size - 1] == 'P'&&a[size - 2] == 'P')
                    {
                        size = size - 1;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
                else
                {
                    ans = false;
                    break;
                }
                i = i + 2;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (size > 1)
        ans = false;
    if (ans)
        cout << "PPAP" << '\n';
    else
        cout << "NP" << '\n';
}