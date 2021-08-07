// submitting this brute force initially
#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--) {
		long long int X,Y,L,R;
		cin >> X >> Y >> L >> R;
		long long Z, maxProd = INT_MIN, prod;
		for(long long int i=L; i<=R; i++)
		{
			prod = (X&i)*(Y&i);
			//cout << prod << endl;
			if(prod > maxProd){
				maxProd = prod;
				Z = i;
			}
		}
		//cout << "Z = " << Z << ", Prod = " << maxProd << endl;
		cout << Z << endl;
	}
	return 0;
}
