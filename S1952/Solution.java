import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	public static int min(int a, int b) {return a>b?b:a;}
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for(int test_case=1;test_case<=T;++test_case) {
			int[] a=new int[4];
			int[] b=new int[13];
			int[] d=new int[13];
			StringTokenizer st=new StringTokenizer(br.readLine().trim(), " ");
			for(int i=0;i<4;++i) a[i]=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(br.readLine().trim(), " ");
			for(int i=1;i<=12;++i) b[i]=Integer.parseInt(st.nextToken());
			for (int i = 1; i <= 12; ++i) {
				if (i >= 3) {
					if (b[i] * a[0] >= a[1])d[i] = min(d[i - 1] + a[1], d[i - 3] + a[2]);
					else d[i] = min(d[i - 1] + b[i] * a[0], d[i - 3] + a[2]);
				}
				else d[i] = min(d[i - 1] + a[1], d[i - 1] + b[i] * a[0]);
			}
			int ans = min(a[3], d[12]);
			System.out.printf("#%d %d\n", test_case, ans);
		}
	}
}
