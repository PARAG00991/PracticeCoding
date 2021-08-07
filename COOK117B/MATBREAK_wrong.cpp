#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--) {
		long long N, A;
		cin >> N >> A;
		//First calc powers till A^(2*N-1)
		if (A == 0) {
			cout << 0 << endl;
			continue;
		}

		long long powers[2*N];
		int i = 1;
		long long res = 1;
		while (i <= (2*N - 1)){
			res = (res * A) % MOD;
			powers[i] = res;
			cout << powers[i] << endl;
			i++;
		}
		long long ans = powers[2*N - 1];
		for(int i = 2*N - 2; i > 0; i-=2) {
			ans = ((ans * powers[i]) % MOD + powers[i-1])%MOD;
		}
		cout << ans << endl;
	}
return 0;
}
