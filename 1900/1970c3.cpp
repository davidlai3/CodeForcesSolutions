#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
/*
 * TLDR: dfs to find winner, tree re-rooting dp to cover all nodes
*/
bool dfs1(int start, vector<vector<int>> &adj, vector<bool> &seen, vector<int> &dp) {
	seen[start] = true;
	bool res = true;
	for (int i : adj[start]) {
		if (seen[i] == false) {
			if (dfs1(i, adj, seen, dp) == true) { // if child is losing pos
				dp[start]++;
				res = false;
			}
		}
	}
	return res;
}

void dfs2(int start, vector<vector<int>> &adj, vector<bool> &seen, vector<int> &dp, vector<bool> &ans) {
	seen[start] = true;
	ans[start] = dp[start] > 0;
	for (int i : adj[start]) {
		if (seen[i] == false) {
			if (dp[i] == 0) dp[start]--;
			if (dp[start] == 0) dp[i]++;
			dfs2(i, adj, seen, dp, ans);
			if (dp[start] == 0) dp[i]--;
			if (dp[i] == 0) dp[start]++;
		}
	}
}

void sol() {    
	int n, t; cin >> n >> t;
	vector<vector<int>> adj(n);
	vector<int> queries(t);
	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	
	for (int i = 0; i < t; ++i) cin >> queries[i];
	vector<int> dp(n,0);
	vector<bool> seen(n, false); 
	vector<bool> ans(n);
	bool root = dfs1(queries[0]-1, adj, seen, dp); // populate dp
	fill(seen.begin(), seen.end(), false);
	dfs2(queries[0]-1, adj, seen, dp, ans);
	cout << (root == true ? "Hermione" : "Ron") << endl;
	for (int i = 1; i < t; ++i) {
		cout << (ans[queries[i]-1] == true ? "Ron" : "Hermione") << endl;
	}
}    
    
    
int main() {    
	ios_base::sync_with_stdio(false);
  int t = 1;    
  //cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
