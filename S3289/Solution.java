import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static class UnionFind{
		int[] p;
		int[] rank;
		public UnionFind(int n) {
			p=new int[n+1];
			rank=new int[n+1];
			for(int i=0;i<=n;++i) {
				p[i]=i;
			}
		}
		int findparent(int x) {
			if (x == p[x]) return x;
			else return p[x] = findparent(p[x]);
		}
		void Union(int x, int y) {
			x = findparent(x);
			y = findparent(y);
			if (rank[x] < rank[y]) p[x] = y;
			else {
				p[y] = x;
				if (rank[x] == rank[y]) ++rank[x];
			}
		}
	}
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			StringTokenizer st =new StringTokenizer(br.readLine().trim()," ");
			int n=Integer.parseInt(st.nextToken());
			int m=Integer.parseInt(st.nextToken());
			UnionFind u=new UnionFind(n);
			System.out.print("#"+test_case+" ");
			for(int i=0;i<m;++i) {
				st=new StringTokenizer(br.readLine().trim(), " ");
				int cmd=Integer.parseInt(st.nextToken());
				int a=Integer.parseInt(st.nextToken());
				int b=Integer.parseInt(st.nextToken());
				if(cmd==0) {
					u.Union(a, b);
				}
				else if(cmd==1) {
					if(u.findparent(a)==u.findparent(b)) System.out.print(1);
					else System.out.print(0);
				}
			}
			System.out.println();
		}
	}
}
