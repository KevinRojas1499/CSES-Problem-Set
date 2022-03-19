#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n,m,q,a,b,c;
	cin>>n>>m>>q;
	ll dist[n+3][n+3];
	ll inf = 1e16;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n ; j++){
			if(i == j) dist[i][i] = 0;
			else dist[i][j] = inf;
		}
	}
	for(int i = 0; i<m; i++){
		cin>>a>>b>>c;
		dist[a][b] = dist[b][a] = min(dist[a][b],c);
	}
	
	for(int k = 1; k<=n; k++){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	for(int i = 0; i<q; i++){
		cin>>a>>b;
		if(dist[a][b] == inf) dist[a][b] = -1;
		cout<<dist[a][b]<<"\n";
	}
	
	
}
