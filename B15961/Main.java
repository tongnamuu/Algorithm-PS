import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int[] a = new int[n];
		int[] cnt=new int[d+1];
		for(int i=0;i<n;++i) {
			a[i]=Integer.parseInt(br.readLine().trim());
		}
		for(int i=0;i<k;++i) {
			cnt[a[i]] += 1;
		}
		cnt[c] += 1;
		int temp = 0;
		int ans = 0;
		for (int i = 0; i <= d; ++i) if (cnt[i] > 0) ++temp;
		int i = 0;
		int j = k;
		while (i < n) {
			cnt[a[i]] -= 1;
			if (cnt[a[i]] == 0) temp--;
			if (cnt[a[k]] == 0) ++temp;
			cnt[a[k]] += 1;
			if (temp > ans) ans = temp;
			i += 1;
			k = (k + 1) % n;
		}
		System.out.println(ans);
	}
}
