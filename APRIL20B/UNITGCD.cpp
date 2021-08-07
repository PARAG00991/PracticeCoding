#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int D = N/2;
		if (N == 1) 
			printf("1\n1 1\n");
			//cout << "1" << endl << "1 1" << endl; 
		else if (N == 2)
			printf("1\n2 1 2\n");
			//cout << "1" << endl << "2 1 2" << endl;
		else {
			printf("%d\n", D);
			//cout << D << endl;
			printf("3 1 2 3\n");
			//cout << "3 1 2 3" << endl;
			int i = 4;
			while (i <= N) {
				if (i == N)
					printf("1 %d\n", i);
					//cout << "1 " << i << endl;
				else
					printf("2 %d %d\n", i, i+1);
					//cout << "2 " << i << " " << i+1 << endl;
				i+=2;
			}
		}
	}
return 0;
}
