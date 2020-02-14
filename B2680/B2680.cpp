#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string decode;
int index;
const string ALP = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZa$%*+-./:";
string DecToHex(int num) {
	string ans;
	while (num) {
		int temp = num % 16;
		if ((num % 16) == 10) ans += 'A';
		else if ((num % 16) == 11) ans += 'B';
		else if ((num % 16) == 12) ans += 'C';
		else if ((num % 16) == 13) ans += 'D';
		else if ((num % 16) == 14) ans += 'E';
		else if ((num % 16) == 15) ans += 'F';
		else ans += (temp + '0');
		num /= 16;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int recoverNum(const string& s) {
	int num = 1;
	int ans = 0;
	int len = s.length();
	for (int i = len - 1; i >= 0; --i) {
		if (s[i] == '1') ans += num;
		num *= 2;
	}
	index += len;
	return ans;
}
int get_countBits() {
	string temp = decode.substr(index, 4);
	index += 4;
	if (temp == "0001") return 1;//Numberic
	if (temp == "0010") return 2;//Alphanumberic
	if (temp == "0100") return 3;//8 bit byte
	if (temp == "1000") return 4;//Kanji
	return 0;
}
string numtoBinaryString(int num) {
	string temp;
	while (num) {
		if (num & 1) {
			temp += '1';
		}
		else temp += '0';
		num >>= 1;
	}
	int len = temp.length();
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < 8 - len; ++i) temp = '0' + temp;
	return temp;
}
string decodeString(const string& s) {
	string temp;
	int len = s.length();
	for (int i = 0; i < len; i += 2) {
		int num = 0;
		if (s[i] <= 'Z'&&s[i] >= 'A') num = s[i] - 'A' + 10;
		else num = s[i] - '0';
		num *= 16;
		if (s[i + 1] <= 'Z'&&s[i + 1] >= 'A') num += s[i + 1] - 'A' + 10;
		else num += (s[i + 1] - '0');
		temp += numtoBinaryString(num);
	}
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--)
	{
		index = 0;
		string ans;
		decode = "";
		string s;
		cin >> s;
		decode = decodeString(s);
		int end = decode.length();
		while (index < end) {
			int c = get_countBits();
			if (c == 1) {
				string mode = decode.substr(index, 10);
				int count = recoverNum(mode);
				for (int l = 0; l < count / 3; ++l) {
					string mode1 = decode.substr(index, 10);
					string temp = to_string(recoverNum(mode1));
					while (temp.length() < 3) temp = '0' + temp;
					ans += temp;
				}
				if (count % 3 == 2) {
					string mode1 = decode.substr(index, 7);
					string temp = to_string(recoverNum(mode1));
					while (temp.length() < 2) temp = '0' + temp;
					ans += temp;
				}
				else if (count % 3 == 1) {
					string mode1 = decode.substr(index, 4);
					string temp = to_string(recoverNum(mode1));
					while (temp.length() < 1) temp = '0' + temp;
					ans += temp;
				}
			}
			else if (c == 2) {
				string mode = decode.substr(index, 9);
				int count = recoverNum(mode);
				for (int l = 0; l < count / 2; ++l) {
					string mode1 = decode.substr(index, 11);
					int num = recoverNum(mode1);
					char f = ALP[num / 45];
					char s = ALP[num % 45];
					if (f == 'a') ans += ' ';
					else ans += f;
					if (s == 'a') ans += ' ';
					else ans += s;
				}
				if (count % 2 == 1) {
					string mode1 = decode.substr(index, 6);
					int num = recoverNum(mode1);
					char s = ALP[num % 45];
					if (s == 'a') ans += ' ';
					else ans += s;
				}
			}
			else if (c == 3) {
				string mode = decode.substr(index, 8);
				int count = recoverNum(mode);
				for (int l = 0; l < count; ++l) {
					string mode1 = decode.substr(index, 8);
					int num = recoverNum(mode1);
					if (num >= 32 && num <= 126) ans += (char)num;
					else {
						ans += '\\';
						string temp = DecToHex(num);
						while (temp.length() < 2) temp = '0' + temp;
						ans += temp;
					}
				}
			}
			else if (c == 4) {
				string mode = decode.substr(index, 8);
				int count = recoverNum(mode);
				for (int l = 0; l < count; ++l) {
					string mode1 = decode.substr(index, 13);
					int num = recoverNum(mode1);
					if (num >= 32 && num <= 126) ans += (char)num;
					else {
						ans += '#';
						string temp = DecToHex(num);
						while (temp.length() < 4) temp = '0' + temp;
						ans += temp;
					}
				}
			}
			else break;
		}
		int len = ans.length();
		int call = len;
		for (int i = 0; i < len; i++) {
			if (ans[i] == '#') call -= 4;
			else if (ans[i] == '\\') call -= 2;
		}
		cout << call << ' ' << ans << '\n';
	}
}
