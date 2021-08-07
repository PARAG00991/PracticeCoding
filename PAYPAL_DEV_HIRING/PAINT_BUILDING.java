import java.util.*;
import java.lang.*;
import java.io.*;

//Building to Building Info
class B2BInfo {
	long  minCost1;	// min cost
	int paintType1;	// paint type for min cost
	long minCost2;	// 2nd min cost
	int paintType2;	// paint type for 2nd min cost

	public B2BInfo() {
		minCost1 = minCost2 = Long.MAX_VALUE;
		paintType1 = paintType2 = -1;
	}
}

class DpInfo {
	long cost;
	int paint;
}

class PAINT_BUILDING
{
	private static Scanner scanner = new Scanner(System.in);
	
	public static void solve() {
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int K = scanner.nextInt();
		int A[] = new int[N+1];
		for(int i=1; i<=N; i++)
			A[i] = scanner.nextInt();
		long[][] cost = new long[N+1][M+1];
		for(int i=1; i<=N; i++)
			for(int j=1; j<=M; j++)
				cost[i][j] = scanner.nextLong();
		
		//Solution starts here

		//Find cumulative cost
		long[][] cumCost = new long[N+1][M+1];
		for(int j=1; j<=M; j++) {
			if(A[1] != j)
				cumCost[1][j] = cost[1][j];
			else
				cumCost[1][j] = 0;
		}

		for(int i=2; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				if(A[i] != j)
					cumCost[i][j] = cumCost[i-1][j] + cost[i][j];
				else
					cumCost[i][j] = cumCost[i-1][j];
			}
		}

		B2BInfo[][] b2bInfoArray = new B2BInfo[N+1][N+1];
		//initialize array
		for(int i=0; i<=N; i++)
			for(int j=0; j<=N; j++)
				b2bInfoArray[i][j] = new B2BInfo();
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(i <= j){
					long min_cost, min_cost2;
					int  paint1, paint2;
					min_cost = min_cost2 = Long.MAX_VALUE;
					paint1 = paint2 = -1;
					for(int k=1; k<=M; k++) {
						long calcCost = cumCost[j][k] - cumCost[i-1][k];
						if(calcCost <= min_cost) {
							min_cost2 = min_cost;
							paint2 = paint1;
							min_cost = calcCost;
							paint1 = k;
						} else if (calcCost < min_cost2) {
							min_cost2 = calcCost;
							paint2 = k;
						}
					}
					b2bInfoArray[i][j].minCost1 = min_cost;
					b2bInfoArray[i][j].minCost2 = min_cost2;
					b2bInfoArray[i][j].paintType1 = paint1;
					b2bInfoArray[i][j].paintType2 = paint2;
				}
			}
		}
		
		//Form dp array now
		DpInfo[][] minCost = new DpInfo[K+1][N+1];
		for(int i=0; i<=K; i++)
			for(int j=0; j<=N; j++)
				minCost[i][j] = new DpInfo();
		//for k=1
		for(int i=1; i<=N; i++) {
			minCost[1][i].cost = b2bInfoArray[1][i].minCost1;
			minCost[1][i].paint = b2bInfoArray[1][i].paintType1;
		}
		for(int i=2; i<=K; i++) {
			for(int j=1; j<=N; j++){
				if(i > j) {
					minCost[i][j].cost = minCost[i][j].paint = -1;
				} else {
					long cost1 = -1;
					int paint1 = -1;
					if (minCost[i][j-1].cost != -1) {
						cost1 = minCost[i][j-1].cost + cost[j][minCost[i][j-1].paint];
						paint1 = minCost[i][j-1].paint;
					}
					long cost2 = Long.MAX_VALUE;
					int  paint2 = -1;
					for(int k=1; k<j; k++) {
						if(minCost[i-1][k].cost != -1) {
							long tempCost = minCost[i-1][k].cost;
							int tempPaint = minCost[i-1][k].paint;
							B2BInfo obj = b2bInfoArray[k+1][j];
							if(obj.paintType1 == tempPaint) {
								//choose 2nd min
								tempCost += obj.minCost2;
								tempPaint = obj.paintType2;
							} else {
								//choose min
								tempCost += obj.minCost1;
								tempPaint = obj.paintType1;
							}
							if(tempCost < cost2){
								cost2 = tempCost;
								paint2 = tempPaint;
							}
						}
					}
					//find min of cost1 and cost2
					if(cost1 == -1) {
						if(cost2 == Long.MAX_VALUE){
							minCost[i][j].cost = minCost[i][j].paint = -1;
						} else {
							minCost[i][j].cost = cost2;
							minCost[i][j].paint = paint2;
						}
					} else {
						if(cost1 < cost2) {
							minCost[i][j].cost = cost1;
							minCost[i][j].paint = paint1;
						} else {
							minCost[i][j].cost = cost2;
							minCost[i][j].paint = paint2;
						}
					}
				}
			}
		}
		System.out.println(minCost[K][N].cost);
	}

	public static void main (String[] args) throws java.lang.Exception
	{
			int T = scanner.nextInt();
			while(T > 0) {
				solve();
				T--;
			}
	}
}
