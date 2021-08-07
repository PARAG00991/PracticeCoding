#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long fastExpo(long long x, long long y) {
	long long res = 1;
	if(x == 0) return 0;
	while(y>0) {
		if(y & 1) res = (res * x)%MOD;
		x = (x * x)%MOD;
		y >>= 1;
	}
	return res;
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		long long N,A;
		cin >> N >> A;
		long long sum = A;
		long long num = A;
		for(int i = 2; i <= N; i++) {
			num = fastExpo(num, 2*(i-1));
			sum = (sum + fastExpo(num, 2*i - 1))%MOD;
		}
		cout << sum << endl;
	}
return 0;
}
