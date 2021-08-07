#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
}

int getNumOfOnesBinary(int num) {
	int ones = 0;
	while(num) {
		if(num & 1)
			ones++;
		num >>= 1;
	}	
	return ones;
}

int main() {
	int T;
	fastscan(T);
	while(T--) {
		int N,Q;
		fastscan(N);
		fastscan(Q);
		int A, odd = 0, even = 0;
		for(int i=0;i<N;i++){
			fastscan(A);
			int ones = getNumOfOnesBinary(A);
			ones % 2 == 1 ? odd++ : even++;
		}
		while(Q--) {
			int P;
			fastscan(P);
			int ones = getNumOfOnesBinary(P);
			if (ones % 2 == 1) {
				printf("%d %d\n", odd, even);
				//cout << odd << " " << even << endl;
			} else {
				printf("%d %d\n", even, odd);
				//cout << even << " " << odd << endl;
			}
		}
	}
	return 0;
}
