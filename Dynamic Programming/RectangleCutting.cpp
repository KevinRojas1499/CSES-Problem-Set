#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n,m,k;
	cin>>n>>m;
	k = max(n,m);
	ll dist[k+1][k+1];
	memset(dist,0, sizeof dist);
	for(int i = 1; i<=k; i++){
		for(int j = 1; j<=k; j++){
			if(i == j){
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = 1e9;
			for(int l = 1; l<j; l++){
				dist[i][j] = min(dist[i][j],1+dist[i][j-l]+dist[i][l]);
			}
			for(int l = 1; l<i; l++){
				dist[i][j] = min(dist[i][j],1+dist[i-l][j]+dist[l][j]);
			}
		}
	}
	cout<<min(dist[n][m],dist[m][n])<<"\n";
}
