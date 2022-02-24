#include <bits/stdc++.h>
#define ll long long 
using namespace std;

  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> p(n);
	ll sum = 0;
	for(int i= 0; i<n; i++){
		cin>>p[i];
		sum+=p[i];
	}
	sort(p.begin(),p.end());
	ll medDown = p[n/2];
	ll medUp = p[(n+1)/2];
	ll res1 = 0, res2 = 0;
	for(int i = 0; i<n; i++){
		res1+= abs(medDown-p[i]);
	}
	for(int i = 0; i<n; i++){
		res2+= abs(medUp-p[i]);
	}
	cout<<min(res1,res2)<<"\n";
}
