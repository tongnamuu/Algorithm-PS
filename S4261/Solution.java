import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		char alp[] = { '2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9' };
		for (int test_case = 1; test_case <= T; ++test_case) {
			StringTokenizer st= new StringTokenizer(br.readLine().trim(), " ");
			String s=st.nextToken();
			int n=Integer.parseInt(st.nextToken());
			st= new StringTokenizer(br.readLine().trim(), " ");
			int ans=0;
			for(int i=0;i<n;++i) {
				String p=st.nextToken();
				int cnt=1;
				for(int j=0;j<p.length();++j) {
					if (alp[p.charAt(j) - 'a'] != s.charAt(j)) {
						cnt=0;
						break;
					}
				}
				ans+=cnt;
			}
			System.out.println("#"+test_case+" "+ans);
		}
	}
}
