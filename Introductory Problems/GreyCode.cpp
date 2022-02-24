#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<string>> greyCode(17);

int main(){

	ll n;
	cin>>n;

	greyCode[0].push_back("");
	for(int i = 1; i<=n; i++){
		
		for(int j = 0; j<greyCode[i-1].size(); j++){
			greyCode[i].push_back("0"+greyCode[i-1][j]);
		}
		for(int j = greyCode[i-1].size()-1;j>=0; j--){
			greyCode[i].push_back("1"+greyCode[i-1][j]);
		}
	}
	
	for(auto code: greyCode[n]){
		cout<<code<<"\n";
	}
	
	
}
