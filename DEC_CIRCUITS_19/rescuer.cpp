#include<bits/stdc++.h>
using namespace std;
double slope(long long x1, long long x2, long long y1, long long y2) {
	return ((double)(y2 - y1))/(x2 - x1);
}
double distance(double x1, double x2, double y1, double y2) {
	return (double)sqrt((y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1));
}
double time(double distance, long long velocity) {
	return (double)distance/velocity;
}
int main() {
	int T;
	cin >> T;
	while(T--) { 
		long long x1, y1, x2, y2, v1, v2;
		cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
		double m, int_x;
		if (x2 == x1){
			m = 1;
			int_x = x1;
		}
		else{
			m = slope(x1, x2, y1, y2);
			cout << m << endl;
			int_x = (double)x1 - ((double)y1/m);
		}
		cout << int_x << endl;
		//find intersection point	
		double dist1 = distance(x1, int_x, y1, 0);
		cout << "dist1 " << dist1<<endl;
		double dist2 = distance(int_x, x2, 0, y2);
		cout << dist2 << endl;
		double ftime = time(dist1, v1) + time(dist2, v2);
		cout << fixed << setprecision(5) << ftime << endl;
	}
	return 0;
}
