#include<bits/stdc++.h>
using namespace std;
//probability based approach - adhoc
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N,M,K,C;
		cin >> N >> M >> K;
		// N are the num of questions in each question paper
		// There are K question papers
		// M is the num of options a question can have
		for (int i = 0; i<N; i++) {
			//create a frequency map for a question
			int freq[M+1];
			memset(freq, 0, sizeof(int)*(M+1));
			for(int j = 0; j<K; j++){
				cin >> C;
				freq[C]++;
			}
			//find and print the option with max freq 
			// it will have max probability
			int max = 0, ans;
			for(int j=1; j<=M; j++){
				if(freq[j]>max){
					max = freq[j];
					ans = j;
				}
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
