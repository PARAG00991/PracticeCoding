#include<bits/stdc++.h>
using namespace std;

class TreeNode 
{
	public:
	int value;
	int depth;
	int parent;

	TreeNode() {
		value = 0;
		depth = -1;
		parent = 0;
	}
};

int fillDepth(TreeNode *nodes, int idx) {
	
	if (nodes[idx].depth != -1)
		return nodes[idx].depth;
	nodes[idx].depth = fillDepth(nodes, nodes[idx].parent) + 1;
	//cout << "ok" << endl;
	return nodes[idx].depth;
}

int findAns(TreeNode *nodes, int a, int b) {
	int depth1 = nodes[a].depth;
	int depth2 = nodes[b].depth;
	int hash[101] = {0,};
	int node1 = a, node2 = b;
	//to make depth1=depth2
	if(depth1 > depth2) {
		while(depth1 != depth2) {
			if(hash[nodes[node1].value] == 0)
				hash[nodes[node1].value]++;
			else
				return 0;
			node1 = nodes[node1].parent;
			depth1--;
		}
	} else if(depth2 > depth1) {
		while(depth1 != depth2) {
			if(hash[nodes[node2].value] == 0)
                hash[nodes[node2].value]++;
            else
                return 0;
            node2 = nodes[node2].parent;
            depth2--;
		}
		//cout << node2 << endl;
	}
	while(node1 != node2) {
		if(hash[nodes[node1].value] == 0)
        	hash[nodes[node1].value]++;
        else
        	return 0;
        node1 = nodes[node1].parent;
	
		if(hash[nodes[node2].value] == 0)
        	hash[nodes[node2].value]++;
        else
        	return 0;
        node2 = nodes[node2].parent;
	}

	//insert lca as well in hash
	if(hash[nodes[node1].value] == 0)
    	hash[nodes[node1].value]++;
    else
    	return 0;
	
	//cout << hash[5] << " " << hash[6] << endl;

	int min = INT_MAX;
	int lastVal = -1;
	for(int i=1; i<=100; i++) {
		if(hash[i] == 1) {
			if(lastVal != -1) {
				int temp = i - lastVal;
				if(temp < min)
					min = temp;
			}
			lastVal = i;
		}
	}
	return min;
}

void solve() {
	int N, Q;
	cin >> N >> Q;
	TreeNode *nodes = new TreeNode[N+1];
	for(int i=1; i<=N; i++) {
		cin >> nodes[i].value;
	}
	int u,v;
	for(int i=1; i<N; i++) {
		//edge = u->v
		cin >> u >> v;
		// implies u is a parent of v
		nodes[v].parent = u;
	}
	
	// to find root node of tree
	// one with parent = 0
	int root;
	for(int i=1; i<=N; i++) {
		if(nodes[i].parent == 0) {
			root = i;
			break;
		}
	}
	nodes[root].depth = 0;

	// to fill depth of all nodes of tree
	for(int i=1; i<=N; i++) {
		if(nodes[i].depth == -1) {
			int depth = fillDepth(nodes, i);
			//cout << "depth = " << depth << endl;
			//cout << "hi";
		}
	}

	int a,b;
	while(Q--) {
		cin >> a >> b;
		int ans = findAns(nodes, a, b);
		cout << ans << endl;
	}
}

int main() {
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
