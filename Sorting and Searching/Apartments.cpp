#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll> a(n),b(m);
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	for(int i = 0; i<m; i++){
		cin>>b[i];
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	ll res = 0;
	int apart = 0;
	for(int i = 0; i<m && apart<n; i++){
		
		while(apart<n && b[i]-k>a[apart] ){
			apart++;
		}
		if(b[i]-k<=a[apart] && a[apart]<= b[i]+k){
			res++;	
			apart++;
		}
	}
	cout<<res<<"\n";


}
