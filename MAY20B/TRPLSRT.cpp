#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int N,K;
		bool solution = true;
		cin >> N >> K;
		int p[N+1];
		bool visited[N+1];
		memset(visited, false, N+1);
		for(int i=1; i<=N; i++){
			cin >> p[i];
		}
		vector<vector<int> > output;
		vector<vector<int> > pairs;
		int count = 0;
		int i=1;
		while(i<=N) {
			if(count > K) {
				solution = false;
				break;
			}
			if(visited[i] == false) {
				int idx1 = i, idx2 = p[i], idx3 = p[p[i]];
				if(idx1 == idx2) {
					//element in place
					visited[i] = true;
				} else if(idx1 == idx3) {
					// doublet
					vector<int> temp;
					temp.push_back(idx1);
					temp.push_back(idx2);
					pairs.push_back(temp);
					visited[idx1] = visited[idx2] = true;
				} else if (p[idx3] == idx1) {
					// we get a triplet
					vector<int> triplet;
					triplet.push_back(idx1);
					triplet.push_back(idx2);
					triplet.push_back(idx3);
					output.push_back(triplet);
					visited[idx1] = visited[idx2] = visited[idx3] = true;
					count++;
				} else {
					vector<int> triplet;			
					triplet.push_back(idx1);
					triplet.push_back(idx2);
					triplet.push_back(idx3);
					output.push_back(triplet);
					count++;
					visited[idx2] = visited[idx3] = true;
					p[idx1] = p[idx3];
					continue;
				}
			}
			i++;
		}

		//now deal with pairs
		int size = pairs.size();
		if(size %2 == 1) {
			solution = false;
		} else {
			//number of pairs are even
			for(int i=0; i<size; i+=2) {
				if(count > K) {
					solution = false;
					break;
				}
				vector<int> triplet1, triplet2;
				triplet1.push_back(pairs[i][0]);
				triplet1.push_back(pairs[i][1]);
				triplet1.push_back(pairs[i+1][0]);
				output.push_back(triplet1);
				triplet2.push_back(pairs[i+1][0]);
				triplet2.push_back(pairs[i][0]);
				triplet2.push_back(pairs[i+1][1]);
				output.push_back(triplet2);
				count += 2;
			}
		}
		
		if(solution == false || count > K) {
			cout << -1 << endl;
		} else {
			cout << count << endl;
			for(int i=0; i<output.size(); i++) {
				cout << output[i][0] << " " << output[i][1] << " " << output[i][2] << endl;
			}
		}
	}
return 0;
}
