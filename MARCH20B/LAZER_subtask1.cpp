#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N,Q;
		cin >> N >> Q;
		int A[N];
		for(int i=0; i<N; i++) 
			cin >> A[i];
		while(Q--) {
			int x1, x2, y;
			cin >> x1 >> x2 >> y;
			int count = 0;
			for(int i=x1-1; i<x2-1; i++) {
				if((A[i] <= y && A[i+1] >= y) || (A[i] >= y && A[i+1] <= y))
					count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}
