import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Solution {
	static int n;
	static int ans;
	static boolean[] check;
	static int[][] a;
	static int dx[] = { 1, -1, -1, 1 };
	static int dy[] = { 1, 1, -1, -1 };
	static int sx, sy;
	public static void go(int x, int y, int dir, int val) {
		if(dir<4) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			if (!check[a[nx][ny]]) {
				check[a[nx][ny]] = true;
				go(nx, ny, dir + 1, val + 1);
				go(nx, ny, dir, val + 1);
				check[a[nx][ny]] = false;
			}
			else if (nx == sx && ny == sy) {
				if (val > ans) ans = val;
				return;
			}
			else return;
		}
		}
		else return;
	}
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int T=sc.nextInt();
		for(int test_case=1;test_case<=T;++test_case) {
			n=sc.nextInt();
			ans=-1;
			a=new int[n][n];
			check=new boolean[101];
			for(int i=0;i<n;++i)for(int j=0;j<n;++j) a[i][j]=sc.nextInt();
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == 0 && j == n - 1) continue;
					else if (i == 0 && j == 0) continue;
					else if (i == n - 1 && j == 0) continue;
					else if (i == n - 1 && j == n - 1) continue;
					sx = i;
					sy = j;
					check[a[i][j]] = true;
					go(i, j, 0, 1);
					check[a[i][j]] = false;
				}
			}
			System.out.printf("#%d %d\n",test_case,ans);
		}
	}
}
