#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;
ll dp[(1<<20)][20];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,m,a,b;
    cin>>n>>m;
    ll count[n][n]; 
    memset(count,0,sizeof count);
    ll tot = 1<<n; 
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        a--,b--;
        count[a][b]++;
    }
    memset(dp,0,sizeof dp);
    //dp[S][k] = # of paths using subset S finishing in k
    dp[1][0] = 1;
    for(int s = 2; s < tot; s++){
        if(!(s & 1)) continue;
        for(int k = 1; k<n; k++){
            if(s < (1<<k)) break;
            if(!(s & (1<<k))) continue;
            for(int l = 0; l<n; l++){
                if(s & (1<<l) && count[l][k]){
                    dp[s][k]+= (count[l][k]*dp[s & ~(1<<k)][l]);
                    dp[s][k]%=MOD;
                }
            }
        }
    }
    ll res = dp[tot-1][n-1];
    cout<<(res+MOD)%MOD<<'\n';
}