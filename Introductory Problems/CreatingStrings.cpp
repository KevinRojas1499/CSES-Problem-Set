#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s;
int n;
string currentPermutation;
vector<bool> chosen;
map<string, bool> seen;
ll tot = 1;

void permutation(int k){
	if(k == n){
		if(seen.find(currentPermutation) == seen.end()){
			cout<<currentPermutation<<"\n";
			tot++;
		}
		seen[currentPermutation] = 1;
	}
	
	for(int i = 0; i<n; i++){
		if(!chosen[i]){
			currentPermutation+=s[i];
			chosen[i] = 1;
			permutation(k+1);
			currentPermutation.pop_back();
			chosen[i] = 0;
		}
	}
}

int main(){
	cin>>s;
	n = s.size();
	sort(s.begin(),s.end());
	chosen.resize(n);
	map<char,int> count;
	for(unsigned int i = 0; i<s.size(); i++){
		if(count.find(s[i]) == count.end()){
			count[s[i]] = 0;
		}
		count[s[i]]++;
		tot*=(i+1);
	}
	for(auto a : count){
		for(int i = 1; i<=a.second; i++){
			tot/=i;
		}
	}
	
	cout<<tot<<"\n";
	permutation(0);
	
}
