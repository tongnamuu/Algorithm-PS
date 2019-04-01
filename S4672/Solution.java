import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			String s=br.readLine().trim();
			int[] d=new int[26];
			int len=s.length();
			for(int i=0;i<len;++i) {
				++d[s.charAt(i) - 'a'];
			}
			int ans = 0;
			for (int i = 0; i < 26; ++i) {
				ans += (d[i] * d[i] + d[i]) / 2;
			}
			System.out.println("#"+test_case+" "+ans);
		}
	}
}
