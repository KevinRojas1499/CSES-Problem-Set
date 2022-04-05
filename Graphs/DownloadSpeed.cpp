#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll n,m,a,b,c, inf = 1e16;
vector<vector<ll>> capacity, adj;
 
ll bfs(vector<ll> &parent){
    parent.assign(parent.size(),-1);
    parent[1] = -2;
    queue<pair<ll,ll>> q;
    q.push({1,inf});
    while(q.size()){
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for(auto next : adj[cur]){
            if(parent[next] == -1 && capacity[cur][next]){
                //if not seen and has capacity
                parent[next] = cur;
                ll new_flow = min(flow,capacity[cur][next]);
                if(next == n) return new_flow;
                q.push({next,new_flow});
            }
        }
 
    }
    return 0;
}
 
int main(){
    cin>>n>>m;
    capacity.resize(n+1);
    for(int i = 0; i<=n; i++) capacity[i].resize(n+1,0);
    adj.resize(n+1);
    for(int i = 0; i<m; i++){
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] += c;
        capacity[b][a] = 0;
    }
    ll flow = 0;
    vector<ll> parent(n+1);
    ll newFlow = 0;
    while(newFlow = bfs(parent)){
        //Encuentra un nuevo aumentingPath
        ll cur = n;
        flow+=newFlow;
        while(cur!=1){
            //Update the residual graph
            ll prev = parent[cur];
            capacity[prev][cur]-=newFlow;
            capacity[cur][prev]+=newFlow;
            cur = prev;
        }
    }
    cout<< flow<<"\n";
}