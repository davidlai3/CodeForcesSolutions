#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
    
void sol() {    
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int rStart = min(a, b);
	int rEnd = max(a, b);
	int bStart = min(c, d);
	int bEnd = max(c, d);

	if (bStart >= rStart && bStart <= rEnd) {
		if (bEnd < rStart || bEnd > rEnd) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else if (bEnd >= rStart && bEnd <= rEnd) {
		if (bStart < rStart || bStart > rEnd) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}




		
}    
    
    
int main() {    
  int t = 1;    
  cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
