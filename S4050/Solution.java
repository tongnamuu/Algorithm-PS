import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			int n = Integer.parseInt(br.readLine().trim());
			int[] a = new int[n];
			int sum=0;
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for(int i=0;i<n;++i) {
				a[i]=Integer.parseInt(st.nextToken());
				sum+=a[i];
			}
			Arrays.sort(a);
			for(int i=n-3;i>=0;i-=3) sum-=a[i];
			System.out.println("#"+test_case+" "+sum);
		}
	}
}
