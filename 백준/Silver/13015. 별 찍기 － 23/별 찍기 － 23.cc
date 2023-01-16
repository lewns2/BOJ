#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INF 1e9


int main() {
	ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int n; cin >> n;

	bool flag = true;
	int posLL = 1;
	int posLR = n;
	int posRL = n + (n-2) * 2;
	int posRR = n + n + (n-2) * 2 - 1;

	for(int i=0; i<2*n-1; i++) {
		if(i == 0 || i == 2*n-2) {
			for(int j=0; j<n; j++) {
			cout << "*";
			}
			for(int j=0; j<(n-2) * 2 + 1; j++) {
				cout << " ";
			}
			for(int j=0; j<n; j++) {
				cout  << "*";
			}
		}
		else {
			for(int j=0; j<=(n + n + (n-2) * 2 - 1); j++) {
				if(j > posRR) break;
				if(j == posLL || j == posLR || j == posRL || j == posRR) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
			
			if(posLR >= posRL) {
				flag = false;	
			}
			if(flag) {
				posLL++;
				posLR++;
				posRL--;
				posRR--;
			}
			else {
				posLL--;
				posLR--;
				posRL++;
				posRR++;
			}
		}
		
		cout << "\n";
	}
} 
