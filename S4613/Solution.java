import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int n=Integer.parseInt(st.nextToken());
			int m=Integer.parseInt(st.nextToken());
			int[][] cnt=new int[n][3];
			for(int i=0;i<n;++i) {
				String temp=br.readLine();
				for(int j=0;j<m;++j) {
					if(temp.charAt(j)=='W') ++cnt[i][0];
					else if(temp.charAt(j)=='B') ++cnt[i][1];
					else if(temp.charAt(j)=='R') ++cnt[i][2];
				}
			}
			for(int i=1;i<n;++i) {
				for(int j=0;j<3;++j) {
					cnt[i][j]+=cnt[i-1][j];
				}
			}
			int ans=2147483647;
			for(int i=0;i<n;++i) {
				for(int j=i+1;j<n-1;++j) {
					ans=min(ans,n*m-(cnt[i][0]+cnt[j][1]-cnt[i][1]+cnt[n-1][2]-cnt[j][2]));
				}
			}
			System.out.println("#"+test_case+" "+ans);
		}
	}

	public static int min(int a, int b) {
		return a>b ? b: a;
	}
}
