import java.util.*;
import java.lang.*;
import java.io.*;
//import javafx.util.*;
class FreqPair {
	Integer freq;
	Integer idx;
}
class MAX_SUM
{
	private static Scanner scanner = new Scanner(System.in);
	public static void solve() {
		int N = scanner.nextInt();
		int K = scanner.nextInt();
		int A[] = new int[N];
		for(int i = 0; i < N; i++)
			A[i] = scanner.nextInt();
		Integer B[] = new Integer[N];
		for(int i=0; i<N; i++)
			B[i] = A[i];
		int freq[] = new int[N];
		while(K > 0) {
			int X = scanner.nextInt();
			int Y = scanner.nextInt();
			freq[X-1]++;
			if(Y != N)	freq[Y]--;
			K--;
		}
		for(int i=1; i<N; i++) freq[i] += freq[i-1];
		List<FreqPair> freqAndIdx = new ArrayList<FreqPair>();
		for(int i=0; i<N; i++) {
			FreqPair fp = new FreqPair();
			fp.freq = freq[i];
			fp.idx = i;
			freqAndIdx.add(fp);
		}
		Collections.sort(freqAndIdx, new Comparator<FreqPair>() {
   			@Override
    		public int compare(final FreqPair o1, final FreqPair o2) {
    			return o2.freq - o1.freq;
			}
		});
		Arrays.sort(B, Collections.reverseOrder());
		int res = 0;
		for(int i=0; i<N; i++){
			res += (freqAndIdx.get(i).freq*(B[i] - A[freqAndIdx.get(i).idx]));
		}
		System.out.println(res);		
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		int T = scanner.nextInt();
		while(T > 0) {
			solve();
			T--;
		}
		scanner.close();
	}
}
