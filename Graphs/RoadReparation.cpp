#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> rep, sizeSet;
vector<tuple<ll,ll,ll>> adj;

ll setOf(ll u){
    if( u == rep[u]){
        return u;
    }
    else{
        return rep[u] = setOf(rep[u]);
    }
}


void unions(ll u, ll v){
    if(setOf(u) == setOf(v)){
        return;
    }
    rep[rep[v]] = rep[rep[u]];

}

int main(){
    ll n,m,a,b,c;
    cin>>n>>m;
    rep.resize(n+1);
    sizeSet.assign(n+1,1);
    for(int i = 1; i<=n; i++){
        rep[i] = i;
    }
    for(int i = 0; i<m; i++){
        cin>>a>>b>>c;
        adj.push_back({c,a,b});
    }

    sort(adj.begin(),adj.end());
    ll res = 0;
    for(auto [d,u,v] : adj){
        if(setOf(u) == setOf(v)) continue;
        else{
            res+= d;
            unions(u,v);
            n--;
        }
    }

    if(n != 1){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<res<<"\n";

    }


    
}