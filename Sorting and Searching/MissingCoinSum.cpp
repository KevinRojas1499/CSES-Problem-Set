#include <bits/stdc++.h>
#define ll long long 
using namespace std;

  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> p(n);
	for(int i= 0; i<n; i++){
		cin>>p[i];
	}
	sort(p.begin(),p.end());
	ll lastNumber = 0;
	
	for(int i = 0; i<n; i++){
		if(p[i] <= lastNumber+1){
			lastNumber = lastNumber+p[i];
		}
		else{
			break;
		}
	}
	cout<<lastNumber+1<<"\n";
			
}
