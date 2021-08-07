#include<bits/stdc++.h>
using namespace std;

bool primeFactors(int n, int k)  
{  
	int count = 0;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        //cout << 2 << " ";
		count++;
		if(count >= k) {
			return true;
		}	 
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
			count++;
            if(count >= k) {
				return true;
			}
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        count++;
	if(count >= k)
		return true;
	else
		return false;
}  

int main(){
	int T;
	cin >> T;
	while(T--) {
		int X,K;
		cin >> X >> K;
		bool status = primeFactors(X, K);
		if(status)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
return 0;
}
