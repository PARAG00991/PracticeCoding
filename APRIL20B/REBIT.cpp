//Author :-  Parag Jain
#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long gcdExtended(long long a, long long b, long long *x, long long *y);

/*
	Lookup Table Format
	'Op1', 'Op2', 'Bitwise &', 'Bitwise |', 'Bitwise ^'
*/
char lookupTruthTable[16][5] = {
	{'0', '0', '0', '0', '0'},
	{'0', '1', '0', '1', '1'},
	{'1', '1', '1', '1', '0'},
	{'a', '0', '0', 'a', 'a'},
	{'a', '1', 'a', '1', 'A'},
	{'a', 'a', 'a', 'a', '0'},
	{'a', 'A', '0', '1', '1'},
	{'A', '0', '0', 'A', 'A'},
	{'A', '1', 'A', '1', 'a'},
	{'A', 'A', 'A', 'A', '0'},
	{'1', '0', '0', '1', '1'},
	{'0', 'a', '0', 'a', 'a'},
	{'1', 'a', 'a', '1', 'A'},
	{'A', 'a', '0', '1', '1'},
	{'0', 'A', '0', 'A', 'A'},
	{'1', 'A', 'A', '1', 'a'}
};

map<char, int> vectorIndexLocator;

void init() {
	vectorIndexLocator['0'] = 0;
	vectorIndexLocator['1'] = 1;
	vectorIndexLocator['a'] = 2;
	vectorIndexLocator['A'] = 3;
}

void populateResultVector(vector<long long> &op1, vector<long long> &op2, char operation, vector<long long> &result) {
	int lookup_index;
	switch(operation) {
		case '&':
			lookup_index = 2;
			break;
		case '|':
			lookup_index = 3;
			break;
		case '^':
			lookup_index = 4;
			break;
	}
	//vector<int> result{ 0, 0, 0, 0 };
	for(int i=0; i<16; i++) {
		result[vectorIndexLocator.find(lookupTruthTable[i][lookup_index])->second] =
			(result[vectorIndexLocator.find(lookupTruthTable[i][lookup_index])->second] +  
			(op1[vectorIndexLocator.find(lookupTruthTable[i][0])->second] *
			op2[vectorIndexLocator.find(lookupTruthTable[i][1])->second]) % MOD) % MOD;
	}
	//return result;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
long long power(long long x, unsigned long long y)  
{  
    long long res = 1;     // Initialize result  
  
    x = x % MOD; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % MOD;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % MOD;  
    }  
    return res;  
}

// Function to find modulo inverse of a 
long long modInverse(long long a, long long m) 
{ 
    long long x, y; 
    long long g = gcdExtended(a, m, &x, &y);
	//cout << g << endl; 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // m is added to handle negative x 
        long long res = (x%m + m) % m; 
        //cout << "Modular multiplicative inverse is " << res;
		return res; 
    } 
	return 0;
} 
  
// C function for extended Euclidean Algorithm 
long long gcdExtended(long long a, long long b, long long *x, long long *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    long long x1, y1; // To store results of recursive call 
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		string L;
		cin >> L;
		stack <pair <char, vector<long long> > > S;
		vector<long long> default_vect = { 1, 1, 1, 1 };
		init();
		int i=0;
		unsigned int hashcount = 0;
		vector<long long> result;
		vector<long long> emptyVector;
		while(L[i]) {
			result = {0, 0, 0, 0};
			if(L[i] == '(' || L[i] == '&' || L[i] == '|' || L[i] == '^') {
				S.push(make_pair(L[i], emptyVector));
			} else if (L[i] == '#') {
				hashcount++;
				S.push(make_pair(L[i], default_vect));
			} else if(L[i] == ')') {
				//Assumption here is that the format 
				// will always be of the form (# op #)
				vector<long long> op2 = S.top().second;
				S.pop();
				char operation = S.top().first;
				S.pop();
				vector<long long> op1 = S.top().second;
				S.pop();
				//Pop out opening brace
				S.pop();
				populateResultVector(op1, op2, operation, result);
				S.push(make_pair('#', result));
			}
			i++;
		}
		if(S.size() == 1) {
			result = S.top().second;
		} else {
			cout << "Something went wrong" << endl;
		}
		// calculating (4^hashcount)%MOD
		long long int q = power(4, hashcount);
	
		// now calculating (q^-1)%MOD
		long long int qinverse = modInverse(q, MOD);
		//cout << "inverse -> " << qinverse << endl;
		//printing final output
		for(int i=0; i<4; i++) {
			//cout << "result of" << i << " = "	<< result [i] << " ";
			cout << ((result[i])*qinverse)%MOD << " ";
		}
		cout<<endl;
	}	
return 0;
}
