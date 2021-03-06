#include<bits/stdc++.h>
using namespace std;
int findNumDays(long long q[], long long hours_in_a_day, int N) {
	int num_days = 1;
	long long hours_till_now = 0;
	for(int i=0; i<N; i++) {	
		if(hours_till_now + q[i] <= hours_in_a_day){
			hours_till_now += q[i];
		} else {
			num_days++;
			hours_till_now = q[i];
		}
	}
	return num_days;
}
long long binarySearch(long long low, long long high, long long q[], int N, int M) {
//	if(low>high){
		//Ideally this case should never come	
//		return -1;
//	}
	if(low == high)
		return low;
	long long mid = (low + high)/2;
	int num_days = findNumDays(q, mid, N);
	//cout << "low -> " << low << " high -> " << high << " mid -> " << mid << " days -> " << num_days<< endl;
	if(num_days <= M)
		return binarySearch(low, mid, q, N, M);
	else //if (num_days > M)
		return binarySearch(mid + 1, high, q, N, M);
	//else
	//	return binarySearch(low, mid - 1, q, N, M);
}

int main() {
	int N, M;
	cin >> N >> M;
	long long q[N], maximum = 1, sum = 0;
	for(int i = 0; i< N; i++){
		cin >> q[i];
		maximum = max(maximum, q[i]);
		sum += q[i];
	}
	// low and high represents number of time units a person works in a day
	long long low = maximum, high = sum;
	cout << binarySearch(low, high, q, N, M) << endl;
	return 0;
}
