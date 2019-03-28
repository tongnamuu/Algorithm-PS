import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
	static int[][] a;
	public static int go(int r, int c, int w, int h) {
		boolean[] check=new boolean[101];
		for(int i=0;i<=w;++i) {
			if(check[a[r+i][c+i]]) return -1;
			check[a[r+i][c+i]]=true;
			if(check[a[r+h+i][c-h+i]])return -1;
			check[a[r+h+i][c-h+i]]=true;
		}
		for(int i=1;i<h;++i) {
			if(check[a[r+i][c-i]]) return -1;
			check[a[r+i][c-i]]=true;
			if(check[a[r+w+i][c+w-i]]) return -1;
			check[a[r+w+i][c+w-i]]=true;
		}
		return (w+h)*2;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			int n = Integer.parseInt(br.readLine().trim());
			a = new int[n][n];
			for (int i = 0; i < n; ++i) {
				StringTokenizer st=new StringTokenizer(br.readLine().trim(), " ");
				for (int j = 0; j < n; ++j) {
					a[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			int ans = -1;
			for(int r=0;r<n;++r) {//(r,c) 시작, (r+w,c+w)  (r+h,c-h), (r+h+w,c-h+w) 가 n보다 작아야한다
				for(int c=0;c<n;++c) {
					for(int w=1;w<n;++w) {
						for(int h=1;h<n;++h) {
							if(r+h+w>=n||c+w>=n||c-h<0 ) continue;
								int cnt=go(r,c,w,h);
								if(ans<cnt) ans=cnt;
								
							
						}
					}
				}
			}
			System.out.printf("#%d %d\n", test_case, ans);
		}
	}
}
