#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
ll n,k, m;
multiset<ll> low,high;
 
 
void insert(ll a){
	if(low.size() == 0){
		low.insert(a);
		return;
	}
	ll med = *low.rbegin();
	if(med<a){
		high.insert(a);
		if(high.size() > k/2){
			auto it = high.begin();
			low.insert(*it);
			high.erase(it);
		}
	}
	else{
		low.insert(a);
		if(low.size()> (k+1)/2){
			high.insert(med);
			low.erase(low.find(med));
		}
	}
}
 
void erase(ll a){
	if(high.find(a) != high.end()) high.erase(high.find(a));
	else low.erase(low.find(a));
	if(low.empty() && high.size()>0){
		low.insert(*high.begin());
		high.erase(high.begin());
	}
}
			
		
 
 
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	cin>>n>>k;
	vector<ll> x(n);
	
	for(int i = 0; i<n; i++){
		cin>>x[i];
 
	}
	
	for(int i = 0; i<n; i++){
		insert(x[i]);
		if(i>=k-1){
			cout<< *low.rbegin()<<" ";
			erase(x[i-k+1]);
		}
	}
 
 
}
