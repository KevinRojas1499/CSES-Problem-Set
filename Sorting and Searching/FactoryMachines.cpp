#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,t;

bool possible(ll time, vector<ll> &times){
	ll tot = 0;
	for(int i = 0; i<n;i++){
		tot+= time/times[i];
	}
	return tot>=t;
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	cin>>n>>t;
	vector<ll> k(n);
	ll M = -1;
	
	for(int i = 0; i<n; i++){
		cin>>k[i];
		if(i == 0) M = k[i];
		M = min(M,k[i]);
	}
	
	ll a = 0,b = M*t,c;
	
	while(a<=b){
		c = a+(b-a)/2;
		if(possible(c,k)){
			b = c-1;
		}
		else{
			a = c+1;
		}
	}
	cout<<a<<"\n";
		
}
