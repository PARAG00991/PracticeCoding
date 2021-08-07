// Author --> Parag Jain
#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int A;
		long long int ans = 0;
		int lastMod4Idx = -1, lastMod2Not4Idx = -1, secondLastMod2Not4Idx = -1;
		int idx = 1;	// idx span from 1 to N
		while(N--){
			cin >> A;
			// current number is a multiple of 4
			if(A%4 == 0) {
				ans += idx;
				lastMod4Idx = idx;
			} else if (A%2 == 0) {
				int maxIdx = max(lastMod4Idx, lastMod2Not4Idx);
				if (maxIdx != -1) {
					ans += maxIdx;
				}
				secondLastMod2Not4Idx = lastMod2Not4Idx;
				lastMod2Not4Idx = idx;
			} else {	//odd number
				int maxIdx = max(lastMod4Idx, secondLastMod2Not4Idx);
				if (maxIdx != -1) {
					ans += maxIdx;
				}
				maxIdx = max(lastMod4Idx, lastMod2Not4Idx);
				if (maxIdx != -1) {
					ans += (idx - maxIdx);
				} else {
					ans += idx;
				}
			}
			idx++;
		}
		cout << ans << endl;
	}
return 0;
}
