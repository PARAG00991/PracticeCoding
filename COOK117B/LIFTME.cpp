#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--) {
		int N, Q;
		cin >> N >> Q;
		long long ans = 0;
		int i = 0, f,d, prevD = 0;
		while(Q--) {
			cin >> f >> d;
			ans += abs(prevD - f);
			ans += abs(d - f);
			prevD = d;
		}
		cout << ans << endl;
	}
return 0;
}
