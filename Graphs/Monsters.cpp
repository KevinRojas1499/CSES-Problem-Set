#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 1005;

ll n,m, monsterDepth[mxN][mxN], personalDepth[mxN][mxN], dir[mxN][mxN];
char mat[mxN][mxN];
bool seen[mxN][mxN];

bool isInside(ll i, ll j){
	return 0<=i && i<n && 0<=j && j<m;
}
bool isValid(ll i, ll j){
	return isInside(i,j) && mat[i][j] != '#';
} 

int main(){
	cin>>n>>m;
	ll xBeg = 0, yBeg = 0, xEnd = 0, yEnd = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>mat[i][j];
			if(mat[i][j] == 'A') xBeg = i,yBeg = j;
		}
	}
	
	memset(seen,0,sizeof seen);
	ll dx[4] = {0, 0,1,-1};
	ll dy[4] = {1,-1,0, 0};
	ll possible = 0;
	queue<pair<ll,ll>> q;
	ll inf = 1e9;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			monsterDepth[i][j] = inf;
			personalDepth[i][j] = inf;
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if( mat[i][j] == 'M'){
				q.push({i,j});
				monsterDepth[i][j] = 0;
				seen[i][j] = 1;
			}
		}
	}

	while(q.size()){
		pair<ll,ll> t = q.front(); q.pop();
		for(int k = 0; k<4; k++){
			ll x = t.first+dx[k],y = t.second+dy[k];
			if(isValid(x,y) && mat[x][y] != 'M' && !seen[x][y]){
				q.push({x,y});
				monsterDepth[x][y] = monsterDepth[t.first][t.second]+1;
				seen[x][y] = 1;
			}
		}
	}
	q.push({xBeg,yBeg});
	string s = "";
	personalDepth[xBeg][yBeg] = 0;
	memset(seen,0,sizeof seen);
	seen[xBeg][yBeg] = 1;


	while(q.size()){
		pair<ll,ll> t = q.front(); q.pop();
		for(int k = 0; k<4; k++){
			ll x = t.first+dx[k],y = t.second+dy[k];
			ll posDepth = personalDepth[t.first][t.second]+1;
			if(isValid(x,y) && !seen[x][y] && posDepth< monsterDepth[x][y] && mat[x][y] != 'M'){
				q.push({x,y});
				personalDepth[x][y] = posDepth;
				seen[x][y] = 1;
			}
			else if( !isInside(x,y)){
				possible = 1;
				xEnd = x; yEnd = y;
				personalDepth[x][y] = posDepth;
			}
		}
	}
	
	if(possible){
		string res = "";
		while(xEnd != xBeg || yEnd != yBeg){
			for(int k = 0; k<4; k++){
				ll i = xEnd+dx[k], j = yEnd+dy[k];
				if(isValid(i,j) && personalDepth[i][j] == personalDepth[xEnd][yEnd]-1){
					if(k == 0){
						res+='L';
					}
					else if(k == 1){
						res+='R';
					}
					else if(k == 2){
						res+='U';
					}
					else{
						res+='D';
					}
					xEnd = i; yEnd = j;
					break;
				}
			}
		}
		cout<<"YES\n";
		cout<<res.size()-1<<"\n";
		reverse(res.begin(),res.end());
		cout<<res.substr(0,res.size()-1)<<"\n";
	}
	else{
		cout<<"NO\n";
	}

}
