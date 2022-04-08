#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m,a,b,c, inf = 1e16;
vector<vector<ll>> capacity, adj;
vector<ll> seen;

ll bfs(vector<ll>& parent){
    parent.assign(parent.size(),-1);
    parent[1] = -2;
    queue<pair<ll,ll>> q;
    q.push({1,inf});
    while(q.size()){
        auto [cur,flow] = q.front();
        q.pop();
        for(auto next : adj[cur]){
            if( parent[next] == -1 && capacity[cur][next]){
                parent[next] = cur;
                ll newFlow = min(flow,capacity[cur][next]);
                if(next == n) return newFlow;
                q.push({next,newFlow});
            }
        }
    }
    return 0;
}

void dfs(ll u, set<ll> & A){
    if(seen[u]) return;
    seen[u] = 1;
    A.insert(u);
    for(auto v : adj[u]){
        if(capacity[u][v] > 0 ) dfs(v, A);
    }
}

int main(){
    cin>>n>>m;
    capacity.assign(n+1,vector<ll> (n+1));
    adj.resize(n+1);
    seen.assign(n+1, false);
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] += 1;
        capacity[b][a] += 1;
    }
    
    ll flow = 0;
    ll newFlow = 0;
    vector<ll> parent(n+1);
    while(newFlow = bfs(parent)){
        flow+=newFlow;
        ll cur = n;
        while(cur!= 1){
            ll prev = parent[cur];
            capacity[prev][cur]-= newFlow;
            capacity[cur][prev]+= newFlow;
            cur = prev;
        }
    }
    //We have mincut in flow

    set<ll> A;
    dfs(1, A);
    cout<<flow<<"\n";
    for(auto u : A){
        for(auto v : adj[u]){
            if(A.find(v) == A.end() && capacity[u][v] == 0){
                cout<<u<<" "<<v<<"\n";
            }
        }
    }
}