#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	ll tot = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		tot+=a[i];
	}
	ll sum;
	ll best = tot;
	for(int i = 0; i<=1<<n; i++){
		sum = 0;
		for(int j = 0; j<n; j++){
			if(i  & 1<<j){
				sum+=a[j];
			}
		}
		best = min(best, abs(tot-2*sum));
	}
	cout<<best<<"\n";

}
