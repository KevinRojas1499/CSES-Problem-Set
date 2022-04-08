#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll inf =1e16;

vector<vector<ll>> adj, capacity;

ll bfs(ll s, ll t, vector<ll> & parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s] = -2;
    queue<pair<ll,ll>> q;
    q.push({s,inf});

    while(q.size()){
        auto [cur,flow] = q.front();
        q.pop();
        for(auto v : adj[cur]){
            if(parent[v] == -1 && capacity[cur][v]){
                ll newFlow = min(flow,capacity[cur][v]);
                parent[v] = cur;
                if(v == t) return newFlow;
                q.push({v,newFlow});
            }
        }
    }
    return 0;
}

int main(){
    ll n,m,k,a,b;
    cin>>n>>m>>k;
    adj.resize(n+m+2);
    capacity.resize(n+m+2, vector<ll> (n+m+2));
    for(int i = 0; i<k; i++){
        cin>>a>>b;
        adj[a].push_back(b+n);
        adj[b+n].push_back(a);
        capacity[a][b+n] = 1;
    }

    for(int i = 1; i<=n; i++){
        adj[0].push_back(i);
        adj[i].push_back(0);
        capacity[0][i] = 1;
    }
    for(int i = n+1; i<=n+m; i++){
        adj[i].push_back(n+m+1);
        adj[n+m+1].push_back(i);
        capacity[i][n+m+1] = 1;
    }
    ll flow = 0;
    ll newFlow = 0;
    ll s = 0, t = n+m+1;
    vector<ll> parent(n+m+2);
    while(newFlow = bfs(s,t,parent)){
        flow+=newFlow;
        ll cur = t;
        while(cur != s){
            capacity[parent[cur]][cur]-=newFlow;
            capacity[cur][parent[cur]]+=newFlow;
            cur = parent[cur];
        }
    }
    cout<<flow<<"\n";

    queue<ll> q;
    vector<bool> seen(n+m+2);
    seen[0] = 1;
    q.push(0);
    while(q.size()){
        ll cur = q.front();
        q.pop();
        for(auto v : adj[cur]){
            if(!seen[v] && capacity[cur][v] == 0){
                q.push(v);
                seen[v] = 1;
                if(0<cur && cur<=n && n<v && v<=n+m ){
                    cout<<cur<<" "<<v-n<<"\n";
                }
            }
        }
    }
}