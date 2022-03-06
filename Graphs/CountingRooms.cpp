#include <bits/stdc++.h>
#define ll long long

using namespace std;

char mat[1005][1005];
ll n,m;
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
bool seen[1005][1005];
bool notValid(ll i, ll j){
	return mat[i][j] == '#' || !(0<=i && i<n && 0<=j && j<m);
}
void dfs(ll i, ll j){
	if(seen[i][j] || notValid(i,j)) return;
	seen[i][j] = 1;
	for(int k = 0; k<4; k++){
		dfs(i+dx[k],j+dy[k]);
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0 ; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>mat[i][j];
			seen[i][j] = 0;
		}
	}
	ll res = 0;
	for(int i = 0 ; i<n; i++){
		for(int j = 0; j<m; j++){
			if(mat[i][j] != '#' && !seen[i][j]){
				res++;
				dfs(i,j);
			}
		}
	}
	cout<<res<<'\n';
}
