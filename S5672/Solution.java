import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			int n=Integer.parseInt(br.readLine().trim());
			char[] a=new char[n];
			char[] b=new char[n];
			String ans="";
			for(int i=0;i<n;++i) {
				a[i]=br.readLine().charAt(0);
				b[n-1-i]=a[i];
			}
			int i = 0;int j=0;
			while (ans.length() < n) {
				if (a[i] > b[j]) ans += b[j++];
				else if (a[i] < b[j]) ans += a[i++];
				else {
					int fx = i;
					int bs = j;
					while (fx >= 0 && fx<n&&bs >= 0 && bs<n&&a[fx] == b[bs]) {
						++fx; ++bs;
					}
					if (fx < n&&bs <  n) {
						if (a[fx] > b[bs]) ans += b[j++];
						else if (a[fx] < b[bs]) ans += a[i++];
						else {
							while (ans.length() < n) ans += a[i++];
						}
					}
					else {
						while (ans.length() < n) {
							ans += a[i++];
						}
					}
				}
			}
			System.out.println("#"+test_case+" "+ans);
		}
	}
}
