#include <bits/stdc++.h>
#define ll long long 

using namespace std;


int main () {
    ll n;
    cin>>n;
    vector<set<ll>> adj(n);
    vector<ll> deg(n), chosen(n), parents(n);
    for(int i = 0; i<n-1; i++){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    set<pair<ll,ll>> lowest;
    for(int i = 0; i<n; i++) {
        lowest.insert({deg[i],i});
    }
    ll res = 0;
    while(lowest.size()) {
        auto [d, idx] = *lowest.begin();
        // cout<<d<<" "<<idx<<"\n";
        lowest.erase(lowest.begin());
        if(d == 0) continue;
        ll p = *adj[idx].begin();
        for(auto neigh : adj[p]){
            if(neigh == idx) continue;
            adj[neigh].erase(p);
            lowest.erase(lowest.find({deg[neigh],neigh}));
            deg[neigh]--;
            lowest.insert({deg[neigh],neigh});
        }

        chosen[p] = chosen[idx] = 1;
        lowest.erase({deg[p],p});
        res++;
    }
    cout<<res<<"\n";
}