#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n;
	cin>>n;
	vector<ll> c(n);
	for(int i = 0; i<n ;i++){
		cin>>c[i];
	}
	set<ll> sums, newSums;
	sums.insert(0);
	for(int i = 0; i<n; i++){
		for(auto s: sums){
			newSums.insert(s+c[i]);
		}
		for(auto s: newSums){
			sums.insert(s);
		}
		newSums.clear();
	}
	cout<<sums.size()-1<<"\n";
	for(auto s: sums){
		if(s !=0) cout<<s<<" ";
	} 	
}
