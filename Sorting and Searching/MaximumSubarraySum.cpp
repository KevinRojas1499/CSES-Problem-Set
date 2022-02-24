#include <bits/stdc++.h>
#define ll long long 
using namespace std;

  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i= 0; i<n; i++){
		cin>>a[i];
	}
	
	ll best = a[0], cur = 0;
	for(int i = 0; i<n; i++){
		cur = max(cur+a[i],a[i]);		
		best = max(best,cur);
	}
	cout<<best<<"\n";
	
}
