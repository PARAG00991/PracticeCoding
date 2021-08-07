#include<bits/stdc++.h>
using namespace std;
int path[][2] = { {1,1}, {2,2}, {3,1}, {4,2}, {5,1}, {6,2}, {7,1}, {8,2},
						 {7,3}, {8,4}, {7,3}, {6,4}, {5,3}, {4,4}, {3,3}, {2,4}, {1,3},
						 {2,4}, {1,5}, {2,6}, {3,5}, {4,6}, {5,5}, {6,6}, {7,5}, {8,6},
						 {7,7}, {8,8}, {7,7}, {6,8}, {5,7}, {4,8}, {3,7}, {2,8}, {1,7} };
int main() {
	int T;
	cin >> T;
	while(T--) {
		int r0, c0;
		cin >> r0 >> c0;
		//To find the first move which will be (r0+c0)/2
		int i = 0;
		if(r0 == c0 && r0 == 1){
			cout << 34 << endl;
			i = 1;
		}
		else if (r0 == c0) {
			cout << 35 << endl;
		} else {
			cout << 36 << endl;
			cout << (r0+c0)/2 << " " << (r0+c0)/2 << endl;
		}
		
		while(i<35){
			cout << path[i][0] << " " << path[i][1] << endl;
			i++;
		}
	}
	return 0;
}
