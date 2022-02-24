#include <bits/stdc++.h>
#define ll long long

using namespace std;

void moveFromAtoB(ll n, int a, int b){
	
	if(n == 1){
		cout<<a<<" "<<b<<"\n";
	}
	else{
		int other = 6-a-b;
		moveFromAtoB(n-1,a,other);
		cout<<a<<" "<<b<<"\n";
		moveFromAtoB(n-1,other,b);
	}
		
	
}

int main(){

	ll n;
	cin>>n;
	vector<ll> a(n+1);
	a[1] = 1;
	for(int i = 2; i<=n; i++){
		a[i] = 2*a[i-1]+1;
	}
	cout<<a[n]<<"\n";
	moveFromAtoB(n,1,3);
}
