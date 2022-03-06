#include <bits/stdc++.h>
#define ll long long

using namespace std;

char mat[1005][1005];
ll n,m;
ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};

ll depth[1005][1005];

bool seen[1005][1005];

bool notValid(ll i, ll j){
	return mat[i][j] == '#' || !(0<=i && i<n && 0<=j && j<m);
}

char convert(ll i){
	char dir = 'R';
	if(i == 0){
		dir = 'L';
	}
	if(i == 2){
		dir = 'U';
	}
	if(i == 3){
		dir = 'D';
	}
	return dir;
}
int main(){
	cin>>n>>m;
	ll xBeg, yBeg, xEnd, yEnd;
	for(int i = 0 ; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>mat[i][j];
			if(mat[i][j] == 'A'){
				xBeg = i; yBeg = j;
			}
			if(mat[i][j] == 'B'){
				xEnd = i; yEnd = j;
			}
			seen[i][j] = 0;
		}
	}
	queue<pair<ll,ll>> q;
	q.push({xBeg,yBeg});
	seen[xBeg][yBeg] = 1;
	while(q.size()){
		pair<ll,ll> t = q.front();
		q.pop();
		for(int k = 0; k<4; k++){
			ll i = t.first+dx[k], j = t.second+dy[k];
			if(!seen[i][j] && !notValid(i,j)){
				q.push({i,j});
				seen[i][j] = 1;
				depth[i][j] = depth[t.first][t.second]+1;
			}
		}
	}
	
	if(depth[xEnd][yEnd]>0){
		cout<<"YES\n";
		cout<<depth[xEnd][yEnd]<<"\n";
		string res = "";
		while(xBeg != xEnd || yBeg != yEnd){
			for(int k = 0; k<4; k++){
				ll i = xEnd+dx[k], j = yEnd+dy[k];
				if(!notValid(i,j) && depth[i][j] == depth[xEnd][yEnd]-1){
					res+=convert(k);
					xEnd = i; yEnd = j;
					break;
				}
			}
		}
		reverse(res.begin(),res.end());
		cout<<res<<"\n";
	}
	else{
		cout<<"NO\n";
	}
		
}
