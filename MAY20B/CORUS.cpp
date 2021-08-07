#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--) {
		int N, Q;
		cin >> N >> Q;
		string S;
		cin >> S;
		int virusFreq[26] = {0,}, i=0;
		while(S[i]){
			virusFreq[S[i]-'a']++;
			i++;
		}
		int C;
		while(Q--) {
			cin >> C;
			int count = 0;
			for(int i=0; i<26; i++){
				if(virusFreq[i] > C)
					count += (virusFreq[i] - C);
			}
			cout << count << endl;
		}
	}
return 0;
}
