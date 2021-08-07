#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int A;
		int last1idx = -1, idx = 1;
		bool res = true;
		while(N--) {
			cin >> A;
			if (A == 1) {
				 if (last1idx != -1) {
					if (idx - last1idx < 6){
						res = false;
					}
				}
				last1idx = idx;
			}
			idx++;
		}
		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
return 0;
}
