#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int M,N;
		cin >> N >> M;
		int F[N], P[N];
		for(int i=0; i<N; i++)
			cin >> F[i];
		for(int i=0; i<N; i++)
			cin >> P[i];

		int *count = new int[M];
		//memset(count, -1, sizeof(count));
		for(int i=0; i<M; i++){
            count[i] = -1;
		}
		for(int i=0; i<N; i++){
			if(count[F[i]-1] == -1)
				count[F[i]-1] = P[i];
			else
				count[F[i]-1] += P[i];
		}
		int min = INT_MAX;
		for(int i=0; i<M; i++){
			//cout << count[i] << " ";
			if(count[i] != -1 && count[i] < min) {
				min = count[i];
			}
		}
		cout << min << endl;
	}
	return 0;
}
