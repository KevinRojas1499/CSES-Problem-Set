#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	vector<pair<ll,ll>> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i].first;
		a[i].second = i;
	}
	
	sort(a.begin(),a.end());
	set<ll> indexes;
	indexes.insert(-1);
	vector<ll> res(n,0);
	ll cur = a[0].first;
	for(int  i = 0; i<n; i++){
		ll start = i, end = i;
		while(end<n && a[end].first == cur){	
			auto it = indexes.lower_bound(a[end].second);
			it--;
			res[a[end].second] = *it;
			end++;
		}
		if(end<n){
			cur = a[end].first;
			i = end-1;
		}else{
			break;
		}
		
		for(int j = start; j<end; j++){
			indexes.insert(a[j].second);
		}
	}
	for(auto b: res){
		cout<< b+1 << " ";
	}
	cout<<"\n";
			

}
