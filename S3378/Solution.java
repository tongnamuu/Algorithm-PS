import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {
	static String[] str;
	static String[] pat;
	static int p, n;
	static int prevcnt[];
	static int[] anscnt;

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			p = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			str = new String[p];
			pat = new String[n];
			prevcnt = new int[p];
			anscnt = new int[n + 1];
			Arrays.fill(anscnt, -2);
			for (int i = 0; i < p; ++i) 
				str[i] = br.readLine();	
			for (int i = 0; i < n; ++i)
				pat[i] = br.readLine();
			for (int a = 1; a <= 20; ++a) {
				for (int b = 1; b <= 20; ++b) {
					for (int cc = 1; cc <= 20; ++cc) {
						if (pOK(a,b,cc)) {
							qCheck(a,b,cc);
						}
					}
				}
			}
			StringBuilder sb= new StringBuilder();
			sb.append("#").append(test_case).append(" 0");
			for(int i=1;i<n;++i) {
				sb.append(' ').append(anscnt[i]);
			}
			System.out.println(sb.toString());
			
		}
	}

	public static void qCheck(int r, int c, int s) {
		int x=0;int y=0;int z=0;
		for(int i=0;i<n-1;++i) {
			String s1=pat[i];
			for(int j=0;j<s1.length();++j) {
				if(s1.charAt(j)=='(') ++x;
				else if(s1.charAt(j)==')') --x;
				else if(s1.charAt(j)=='{') ++y;
				else if(s1.charAt(j)=='}') --y;
				else if(s1.charAt(j)=='[') ++z;
				else if(s1.charAt(j)==']') --z;
			}
			int dot=r*x+c*y+s*z;
			if(anscnt[i+1]==-2) {
				anscnt[i+1]=dot;
			}else if(anscnt[i+1]>0 && anscnt[i+1]!=dot) {
				anscnt[i+1]=-1;
			}
		}
	}

	public static boolean pOK(int r, int c, int s) {
		int x=0;int y=0;int z=0;
		int dot=0;
		for(int i=0;i<p;++i) {
			dot=0;
			String s1=str[i];
			int j=0;
			for(j=0;j<s1.length();++j) {
				if(s1.charAt(j)=='.') ++dot;
				else break;
			}
			if(x*r+c*y+s*z!=dot) return false;
			for(;j<s1.length();++j) {
				if(s1.charAt(j)=='(') ++x;
				else if(s1.charAt(j)==')') --x;
				else if(s1.charAt(j)=='{') ++y;
				else if(s1.charAt(j)=='}') --y;
				else if(s1.charAt(j)=='[') ++z;
				else if(s1.charAt(j)==']') --z;
			}
		}
		
		return true;
		
	}

	
}
