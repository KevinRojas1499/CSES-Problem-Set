#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n,m;
	string s,w;
	cin>>s>>w;
	n = s.size(); m = w.size();
	ll dist[n+1][m+1];
	memset(dist,0, sizeof dist);
	dist[0][0] = 0;
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=m; j++){
			if(i != 0 || j!= 0)	dist[i][j] = 1e9;
			if(i-1>=0 && j-1>=0) dist[i][j] = min(dist[i][j],dist[i-1][j-1]+(s[i-1] == w[j-1] ? 0 : 1));
			if(j-1>=0) dist[i][j] = min(dist[i][j-1]+1,dist[i][j]);
			if(i-1>=0) dist[i][j] = min(dist[i-1][j]+1,dist[i][j]);
		}
	}
	cout<<dist[n][m]<<"\n";
}
