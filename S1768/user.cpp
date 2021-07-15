#define N 4
using namespace std;
typedef struct {
    int strike;
    int ball;
} Result;

// API
extern Result query(int guess[]);

int numbers[5041][4];
int fail[200][6];
int fcnt;
int nums[10];
bool compare(int guess[]) {
    for (int i = 0; i < fcnt; ++i) {
        int s = 0, b = 0;
        for (int j = 0; j < 4; ++j) nums[fail[i][j]] = 1;
        for (int j = 0; j < 4; ++j) {
            if (guess[j] == fail[i][j]) {
                s++;
            }
            else if (nums[guess[j]] == 1) {
                b++;
            }
        }
        for (int j = 0; j < 4; ++j) nums[fail[i][j]] = 0;
        if (!(s == fail[i][4] && b == fail[i][5])) return false;
    }
    return true;
}
void doUserImplementation(int guess[]) {
    static bool init = false;
    static int cnt = 0;
    if (!init) {
        init = true;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i == j) continue;
                for (int k = 0; k < 10; ++k) {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < 10; ++l) {
                        if (i == l || j == l || k == l) continue;
                        numbers[cnt][2] = i;
                        numbers[cnt][1] = j;
                        numbers[cnt][3] = k;
                        numbers[cnt][0] = l;
                        ++cnt;

                    }
                }
            }
        }
    } // end of init
    fcnt = 0;
    Result result;
    for (int i = 0; i < cnt; ++i) {
        if (compare(numbers[i])) {
            result = query(numbers[i]);
            if (result.strike == 4) {
                guess[0] = numbers[i][0]; guess[1] = numbers[i][1]; guess[2] = numbers[i][2]; guess[3] = numbers[i][3];
                break;
            }
            fail[fcnt][0] = numbers[i][0];
            fail[fcnt][1] = numbers[i][1];
            fail[fcnt][2] = numbers[i][2];
            fail[fcnt][3] = numbers[i][3];
            fail[fcnt][4] = result.strike;
            fail[fcnt][5] = result.ball;
            fcnt++;
        }
    }
}
