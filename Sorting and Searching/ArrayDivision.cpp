#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,k;
vector<ll> x;

bool possible(ll a){
	ll curSum = 0, pieces = 1;
	for(int i = 0; i<n; i++){
		if(curSum+x[i] > a){
			curSum = x[i];
			if(curSum > a){
				return false;
			}
			pieces++;
		}
		else{
			curSum+=x[i];
		}
	}
	if(pieces<=k){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	cin>>n>>k;
	ll X = 0;
	x.resize(n);
	for(int i = 0; i<n; i++){
		cin>>x[i];
		X+=x[i];
	}
	
	
	ll a = 1, b = X;
	while(a<=b){
		ll c = a+(b-a)/2;
		if(possible(c)){
			b = c-1;
		}
		else{
			a = c+1;
		}
	}
	cout<<a<<"\n";
	
}
