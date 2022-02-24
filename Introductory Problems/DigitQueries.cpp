#include <bits/stdc++.h>
#define ll long long

using namespace std;
//bool print = 0;

int digit(ll a){
	if(a<10) return a;
	ll dig = 1;
	ll cant = 0;
	ll pow  = 1;
	while(cant+dig*9*pow<a){
		cant+= dig*9*pow;
		pow*=10;
		dig++;
	}
	
	ll falta = a-cant-1;
	ll correspondingNumber = falta/dig;//This tells us which number of dig digits we are looking at
	ll digPos = (falta%dig+dig)%dig;
	ll num = pow+correspondingNumber;
	//if(print) cout<<"Num:"<<num<<" digPos:"<<digPos<<" dig: "<<dig<<"\n";
	string number = to_string(num);
	
	return number[digPos]-'0';
}

int main(){
	ll q,a;
	
	cin>>q;
	while(q--){
		cin>>a;
		cout<<digit(a)<<"\n";
	}
}
