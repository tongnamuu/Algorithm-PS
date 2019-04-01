import java.io.IOException;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		for (int test_case = 1; test_case <= T; ++test_case) {
			int n=sc.nextInt();
			int[] a = new int[n];
			for(int i=0;i<n;++i) a[i]=sc.nextInt();
			int upcnt=0;
			int downcnt=0;
			int ans=0;
			if(a[0]<a[1]) ++upcnt;
			int temp=a[1];
			int i=2;
			while(i<n) {
				while(i<n&&a[i]>temp) {
					temp=a[i];
					++i;
					++upcnt;
				}
				if(i==n) break;
				while(i<n&&a[i]<temp) {
					temp=a[i];
					++i;
					++downcnt;
				}
				ans+=upcnt*downcnt;
				upcnt=0;
				downcnt=0; 
			}
			System.out.println("#"+test_case+" "+ans);
		}
	}
}
