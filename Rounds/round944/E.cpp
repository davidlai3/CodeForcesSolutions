#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
    
void sol() {    
	int n, k, q; cin >> n >> k >> q;
	vector<int> a(k+1, 0);
	vector<int> b(k+1, 0);
	vector<int> queries(q);
	for (int i = 1; i <= k; ++i) cin >> a[i];
	for (int i = 1; i <= k; ++i) cin >> b[i];
	for (int i = 0; i < q; ++i) cin >> queries[i];


	for (int qu : queries) { // Run queries
		if (qu == 0) { // Early exit
			cout << 0 << " ";
			continue;
		} 
		int close = distance(a.begin(), lower_bound(a.begin(), a.end(), qu)); // Find closest point
		if (a[close] == qu) { // Early exit
			cout << b[close] << " ";
			continue;
		}
		ll int cur = b[close-1];
		ll int res = qu - a[close-1];
		ll int top = (b[close] - b[close-1]) * res;
		ll int bot = (a[close] - a[close-1]);
		cur += (top/bot);
		cout << cur << " ";
	}
	cout << endl;
}    
    
    
int main() {    
  int t = 1;    
  cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
