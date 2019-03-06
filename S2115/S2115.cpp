#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n, m, c; cin >> n >> m >> c;
		int a[11][11];
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
		int answer = 0;
		if (2 * m <= n) {
			for (int sero = 0; sero < n; ++sero) {
				for (int garo1 = 0; garo1 + m <= n; ++garo1) {
					if (garo1 + m + m <= n) {
						vector<int>player1;
						for (int k = garo1; k < garo1 + m; ++k) {
							player1.push_back(a[sero][k]);
						}
						for (int garo2 = garo1 + m; garo2 + m <= n; ++garo2) {
							vector<int>player2;
							for (int k = garo2; k < garo2 + m; ++k) {
								player2.push_back(a[sero][k]);
							}
							for (int i = 1; i < (1 << m); ++i) {
								int temp = 0;
								int hubo = 0;
								for (int j = 0; j < m; ++j) {
									if (i&(1 << j)) {
										temp += player1[j];
										hubo += player1[j] * player1[j];
									}
								}
								if (temp <= c) {
									for (int i2 = 1; i2 < (1 << m); ++i2) {
										int temp2 = 0;
										int hubo2 = 0;
										for (int j2 = 0; j2 < m; ++j2) {
											if (i2&(1 << j2)) {
												temp2 += player2[j2];
												hubo2 += player2[j2] * player2[j2];
											}
										}
										if (temp2 <= c) {
											if (answer < hubo + hubo2) answer = hubo + hubo2;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for (int sero = 0; sero < n - 1; ++sero) {
			for (int sero1 = sero + 1; sero1 < n; ++sero1) {
				for (int garo = 0; garo + m<= n; ++garo) {
					vector<int>player1;
					for (int k = garo; k < garo + m; ++k) {
						player1.push_back(a[sero][k]);
					}
					for (int garo2 = 0; garo2 + m <= n; ++garo2) {
						vector<int>player2;
						for (int k = garo2; k < garo2 + m; ++k) {
							player2.push_back(a[sero1][k]);
						}
						for (int i = 1; i < (1 << m); ++i) {
							int temp = 0;
							int hubo = 0;
							for (int j = 0; j < m; ++j) {
								if (i&(1 << j)) {
									temp += player1[j];
									hubo += player1[j] * player1[j];
								}
							}
							if (temp <= c) {
								for (int i2 = 1; i2 < (1 << m); ++i2) {
									int temp2 = 0;
									int hubo2 = 0;
									for (int j2 = 0; j2 < m; ++j2) {
										if (i2&(1 << j2)) {
											temp2 += player2[j2];
											hubo2 += player2[j2] * player2[j2];
										}
									}
									if (temp2 <= c) {
										if (answer < hubo + hubo2) answer = hubo + hubo2;
									}
								}
							}
						}
					}
				}
			}
		}
		cout << '#' << test_case << ' ' << answer << '\n';
	}
}