#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int X[N];
		int best = 11, worst = 1;
		for(int i=0; i<N; i++)
			cin >> X[i];

		int count = 1;
		for(int i=1; i<N; i++) {
			int diff = X[i] - X[i-1];
			if(diff <= 2) {
				count++;
			} else {
				if(count > worst) worst = count;
				if(count < best) best = count;
				count = 1;
			}
		}
		if(count > worst) worst = count;
		if(count < best) best = count;
		cout << best << " " << worst << endl;
	}
	return 0;
}
