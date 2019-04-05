import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int[][] a;
	static int n;
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int test_case = 1; test_case <= T; ++test_case) {
			StringTokenizer st = new StringTokenizer(br.readLine().trim(), " ");
			n=Integer.parseInt(st.nextToken());
			String cmd=st.nextToken();
			a=new int[n][n];
			for(int i=0;i<n;++i) {
				st = new StringTokenizer(br.readLine().trim(), " ");
				for(int j=0;j<n;++j) {
					a[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			if(cmd.equals("up")) moveup();
			else if(cmd.equals(("down"))) movedown();
			else if(cmd.equals(("left"))) moveleft();
			else if(cmd.equals(("right"))) moveright();
			System.out.println("#"+test_case);
			for(int i=0;i<n;++i) {
				for(int j=0;j<n;++j)System.out.print(a[i][j]+" ");
				System.out.println();
			}
		}
	}
	static void moveup() {
		for (int k = 0; k < n; ++k) {
			int[] temp=new int[n];
			int index = 0;
			for (int i = 0; i < n;) {
				if (a[i][k] == 0) {
					++i;
					continue;
				}
				boolean indexchange = false;
				for (int j = i + 1; j < n; ++j) {
					if (a[i][k] == a[j][k]) {
						a[i][k] *= 2;
						temp[index++] = a[i][k];
						a[j][k] = 0;
						i = j + 1;
						indexchange = true;
						break;
					}
					else if (a[j][k] > 0 && a[i][k] != a[j][k]) {
						temp[index++] = a[i][k];
						i = j;
						indexchange = true;
						break;
					}
				}
				if (!indexchange) {
					temp[index++] = a[i][k];
					break;
				}
			}
			for (int i = 0; i < n; ++i) {
				a[i][k] = temp[i];
			}
		}
	}
	static void movedown() {
		for (int k = 0; k < n; ++k) {
			int[] temp=new int[n];
			int index = n-1;
			for (int i = n-1; i >=0;) {
				if (a[i][k] == 0) {
					--i;
					continue;
				}
				boolean indexchange = false;
				for (int j = i - 1; j >=0; --j) {
					if (a[i][k] == a[j][k]) {
						a[i][k] *= 2;
						temp[index--] = a[i][k];
						a[j][k] = 0;
						i = j - 1;
						indexchange = true;
						break;
					}
					else if (a[j][k] > 0 && a[i][k] != a[j][k]) {
						temp[index--] = a[i][k];
						i = j;
						indexchange = true;
						break;
					}
				}
				if (!indexchange) {
					temp[index--] = a[i][k];
					break;
				}
			}
			for (int i = 0; i < n; ++i) {
				a[i][k] = temp[i];
			}
		}
	}
	static void moveright() {
		for (int k = 0; k < n; ++k) {
			int[] temp=new int[n];
			int index = n - 1;
			for (int i = n - 1; i >= 0;) {
				if (a[k][i] == 0) {
					--i;
					continue;
				}
				boolean indexchange = false;
				for (int j = i - 1; j >= 0; --j) {
					if (a[k][i] == a[k][j]) {
						a[k][i] *= 2;
						temp[index--] = a[k][i];
						a[k][j] = 0;
						i = j - 1;
						indexchange = true;
						break;
					}
					else if (a[k][j] > 0 && a[k][i] != a[k][j]) {
						temp[index--] = a[k][i];
						i = j;
						indexchange = true;
						break;
					}
				}
				if (!indexchange) {
					temp[index--] = a[k][i];
					break;
				}
			}
			for (int i = 0; i < n; ++i) {
				a[k][i] = temp[i];
			}
		}
	}
	static void moveleft() {
		for (int k = 0; k < n; ++k) {
			int[] temp=new int[n];
			int index = 0;
			for (int i = 0; i < n;) {
				if (a[k][i] == 0) {
					++i;
					continue;
				}
				boolean indexchange = false;
				for (int j = i + 1; j < n; ++j) {
					if (a[k][i] == a[k][j]) {
						a[k][i] *= 2;
						temp[index++] = a[k][i];
						a[k][j] = 0;
						i = j + 1;
						indexchange = true;
						break;
					}
					else if (a[k][j] > 0 && a[k][i] != a[k][j]) {
						temp[index++] = a[k][i];
						i = j;
						indexchange = true;
						break;
					}
				}
				if (!indexchange) {
					temp[index++] = a[k][i];
					break;
				}
			}
			for (int i = 0; i < n; ++i) {
				a[k][i] = temp[i];
			}
		}
	}
}
