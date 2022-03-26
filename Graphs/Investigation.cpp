#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ll n,m,a,b,cc;
    const ll inf = 1e16, MOD = 1e9+7;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i = 0; i<m; i++){
        cin>>a>>b>>cc;
        adj[a].push_back({b,cc});
    }
    set<pair<ll,ll>> pq;
    vector<ll> dist(n+1,inf), num(n+1), minF(n+1,inf), maxF(n+1);
    pq.insert({0,1});
    for(int i = 2; i<=n; i++){
        pq.insert({inf,i});
    }
	dist[1] = 0;
	minF[1] = 0;
	maxF[1] = 0;
	num[1] = 1;
    while(pq.size()){
        auto [d,u] = *pq.begin();
        pq.erase(pq.begin());
        for(auto [v, c]: adj[u]){
            if(d+c < dist[v]){
                dist[v] = d+c;
                num[v] = num[u];
                minF[v] = 1+minF[u];
                maxF[v] = 1+maxF[u];
                pq.insert({d+c,v});
            }
			else if(d+c == dist[v]){
				num[v]+=num[u];
				num[v]%=MOD;
				minF[v] = min(minF[v],1+minF[u]);
				maxF[v] = max(maxF[v],1+maxF[u]);
				
			}
        }
    }
    cout<<dist[n]<<" "<<(num[n]+MOD)%MOD<<" "<<minF[n]<<" "<<maxF[n]<<"\n";

}
