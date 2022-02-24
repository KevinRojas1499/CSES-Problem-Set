#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
ll mod(ll k, ll n){
	return (k%n+n)%n;
}

void print(ordered_set jp){
	cout<<"ARBOL\n";
	for(auto a: jp){
		cout<<a<<" ";
	}
	cout<<"\n";
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	//k++;
	ordered_set jp;
	for(int i = 0; i<n; i++){
		jp.insert(i+1);
	}
	ll cur = k;
	while(jp.size()){
		//print(jp);
		cur = mod(cur,jp.size());
		cout<<*jp.find_by_order(cur)<<" ";
		jp.erase(jp.find_by_order(cur));
		cur+=k;
	}
	
	cout<<"\n";
}
