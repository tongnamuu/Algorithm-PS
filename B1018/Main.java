import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int m;
	static char[][] map;
	static char[][] a = new char[9][9];

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new char[n][m];
		for (int i = 0; i < n; ++i) {
			String temp = br.readLine().trim();
			for (int j = 0; j < m; ++j) {
				map[i][j] = temp.charAt(j);
			}
		}
		int ans = 2147483647;
		for (int i = 0; i + 7 < n; ++i) {
			for (int j = 0; j + 7 < m; ++j) {
				for (int x = 0; x < 8; ++x) {
					for (int y = 0; y < 8; ++y) {
						a[x][y] = map[i + x][j + y];
					}
				}
				ans = min(ans, checkb());
				ans = min(ans, checkw());
			}
		}
		System.out.println(ans);
	}

	public static int checkw() {
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if ((i + j) % 2 == 1) {
					if (a[i][j] == 'W')
						cnt++;
				} else {
					if (a[i][j] == 'B')
						cnt++;
				}
			}
		}
		return cnt;
	}

	public static int checkb() {
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if ((i + j) % 2 == 1) {
					if (a[i][j] == 'B')
						cnt++;
				} else {
					if (a[i][j] == 'W')
						cnt++;
				}
			}
		}
		return cnt;
	}

	public static int min(int a, int b) {
		return a > b ? b : a;
	}
}
