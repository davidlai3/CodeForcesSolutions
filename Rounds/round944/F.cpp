#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
double euclid(int x, int y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}    

void sol() {    
	int r; cin >> r;
	int count = 0;
	int max_height = r;

	for (int i = 0; i <= r; ++i) {
		double distance = euclid(i, max_height);
		if (distance >= r && distance < r+1) {
			count++;
			double below = euclid(i, max_height-1);
			while (below >= r && below < r+1 && max_height-1 > 0) {
				count++;
				max_height--;
				below = euclid(i, max_height-1);
			}
		}
		else max_height--, i--;
	}

	cout << count*4 << endl;

		
}    
    
    
int main() {    
  int t = 1;    
  cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
