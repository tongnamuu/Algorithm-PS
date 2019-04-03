import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		int[][] d = new int[5][5];
		d[1][1] = 1; d[1][2] = 2; d[1][3] = 2; d[1][4] = 2;
		d[2][1] = 2; d[2][2] = 4; d[2][3] = 4; d[2][4] = 4;
		d[3][1] = 2; d[3][2] = 4; d[3][3] = 5; d[3][4] = 6;
		d[4][1] = 2; d[4][2] = 4; d[4][3] = 6; d[4][4] = 8;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int ans = (n / 4)*(m / 4)*d[4][4] + (n / 4)*(d[4][m % 4]) + (m / 4)*(d[n % 4][4]) + d[n % 4][m % 4];
			System.out.println("#"+test_case+" "+ans);
		}
	}
}
