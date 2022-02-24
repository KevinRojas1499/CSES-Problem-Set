#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	vector<ll> t(n);
	ll tot = 0;
	for(int i=0; i<n; i++){
		cin>>t[i];
		tot+=t[i];
	}
	sort(t.rbegin(),t.rend());
	vector<int> read(n);
	ll t1 = 0, t2 = 0;
	ll j = 1;
	for(int i = 0; i<n; i++){
		t1+= t[i];
		
		while(t2<t1 && j<n){
			t2+=t[j];
			read[j] = 1;
			j++;
		}
		if(t2<t1){
			//Llegue al final y estoy esperando
			t2 = t1;
		}
		if(!read[i]){
			t2+=t[i];
			read[i] = 1;
		}
	}
	cout<<t2<<"\n";
		
}
