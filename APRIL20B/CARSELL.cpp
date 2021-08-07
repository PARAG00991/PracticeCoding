#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> P(N);
		for(int i=0; i<N; i++)
			cin >> P[i];
		sort(P.begin(), P.end(), greater<int>());
		long long int ans = 0;
		for(int i=0; i<N; i++) {
			int x = (P[i] - i) >=0 ? (P[i] - i) : 0;
			ans = (ans + x) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
