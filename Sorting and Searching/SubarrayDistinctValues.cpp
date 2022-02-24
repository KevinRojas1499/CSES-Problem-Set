#include <bits/stdc++.h>
#define ll long long 
using namespace std;

multiset<ll> numsWithRep;
set<ll> nums;

void erase(ll a){
	auto it = numsWithRep.find(a);
	if(it != numsWithRep.end()){
		numsWithRep.erase(it);
		if(numsWithRep.find(a) == numsWithRep.end()){
			nums.erase(a);
		}
	}
}

void insert(ll a){
	numsWithRep.insert(a);
	nums.insert(a);
} 
	
	
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n,k;
	cin>>n>>k;
	vector<ll> x(n);
	for(int i = 0; i<n; i++){
		cin>>x[i];
	}
	
	
	ll res = 0;
	ll in = 0;
	for(int i = 0; i<n; i++){
		insert(x[i]);
		while(nums.size() == k+1){
			erase(x[in]);
			in++;
		}
		res+= i-in+1;
	}
	cout<<res<<"\n";
	
}
