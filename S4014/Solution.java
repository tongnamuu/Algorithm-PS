import java.io.IOException;
import java.util.Scanner;

public class Solution {
	static int n;
	static int x;
	static int[] pat;
	static boolean[] up;
	static boolean[] down;
	public static void main(String[] args) throws Exception, IOException {
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		for (int test_case = 1; test_case <= T; ++test_case) {
			n=sc.nextInt();
			x=sc.nextInt();
			int[][] a = new int[n][n];
			for(int i=0;i<n;++i) {
				for(int j=0;j<n;++j) {
					a[i][j]=sc.nextInt();
				}
			}
			pat=new int[n];
			up=new boolean[n];
			down=new boolean[n];
			int ans=0;
			for(int i=0;i<n;++i) {
				for (int j = 0; j < n; ++j) {
					pat[j] = a[i][j];
					up[j] = false;
					down[j] = false;
				}
				if(check()) ++ans;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					pat[j] = a[j][i];
					up[j] = false;
					down[j] = false;
				}
				if (check()) ++ans;
			}
			System.out.println("#"+test_case+" "+ans);
		}
	}
	public static boolean check() {
		for (int i = 0; i< n - 1; ) {
			if (pat[i] - pat[i + 1] >= 2 || pat[i] - pat[i + 1] <= -2) return false;
			if (pat[i] - pat[i + 1] == 1) {
				int temp = pat[i + 1];
				for (int k = 0; k < x; ++k) {
					if (k + i + 1 >= n) return false;
					if (pat[k + i + 1] != temp) return false;
					down[k + i + 1] = true;
				}
				i = i + x;
			}
			else ++i;
		}
		for (int i = n - 1; i >= 1;) {
			if (pat[i] - pat[i - 1] >= 2 || pat[i] - pat[i - 1] <= -2) return false;
			if (pat[i] - pat[i - 1] == 1) {
				int temp = pat[i - 1];
				for (int k = 0; k < x; ++k) {
					if (i - 1 - k < 0) return false;
					if (pat[i - 1 - k] != temp) return false;
					up[i - 1 - k] = true;
				}
				i = i - x;
			}
			else --i;
		}
		for (int i = 0; i < n; ++i) if (up[i] && down[i]) return false;
		return true;
	}
}
