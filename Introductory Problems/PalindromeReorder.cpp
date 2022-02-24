#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	string s;
	cin>>s;
	int n = s.size();
	map<char,int> count;
	for(int i = 0; i<n;i++){
		if(count.find(s[i]) == count.end()) count[s[i]] = 0;
		count[s[i]]++;
	}
	int numOdd = 0;
	char odd = '0';
	for(auto a: count){
		if(a.second%2 != 0){
			numOdd++;
			odd = a.first;
		}
	}
	if(n%2 == 0 && numOdd == 0){
		string res = "";
		for(auto a: count){
			for(int i = 0; i<a.second/2; i++){
				res+=a.first;
			}
		}
		string a = res;
		reverse(a.begin(),a.end());
		res+=a;
		cout<<res<<"\n";
	}
	else if(n%2 !=0 && numOdd == 1){
		string res = "";
		for(auto a: count){
			if(a.second%2 !=0) continue;
			
			for(int i = 0; i<a.second/2; i++){
				res+=a.first;
			}
		}
		string a = res;
		reverse(a.begin(),a.end());
		for(int i = 0; i<count[odd]; i++){
			res+=odd;
		}
		res+=a;
		cout<<res<<"\n";
	}
	else{
		cout<<"NO SOLUTION\n";
	}


}
