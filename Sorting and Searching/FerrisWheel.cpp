#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> p(n);
	vector<bool> chosen(n,0);
	for(int i = 0; i<n; i++){
		cin>>p[i];
	}
	sort(p.begin(),p.end());
	ll other = n-1;
	ll res = 0;
	for(int i = 0; i<n; i++){
		if(chosen[i]) continue;
		if(i>=other){
			chosen[i] = 1;
			res++;
		}
		else{
			while(i<other && p[i]+p[other]>x){
				other--;
			}
			if(i<other && p[i]+p[other]<=x){
				chosen[i] = 1;
				chosen[other] = 1;
				other--;
			}
			res++;
		}
	}
	cout<<res<<"\n";		

}
