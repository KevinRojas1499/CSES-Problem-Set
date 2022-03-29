#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
vector<ll> rep, sizeOfComp;
 
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
    sizeOfComp[setOf(v)] += sizeOfComp[setOf(u)];
    sizeOfComp[setOf(u)] = sizeOfComp[setOf(v)];
    rep[setOf(v)] = rep[setOf(u)];
}
 
ll getSize(ll u){
    return sizeOfComp[setOf(u)];
}
 
int main(){
    ll n,m,a,b;
    cin>>n>>m;
    rep.resize(n+1);
    sizeOfComp.assign(n+1,1);
    for(int i = 1; i<=n; i++){
        rep[i] = i;
    }
    ll maxComp = 1;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        if(setOf(a) != setOf(b)){
            unions(a,b);
            maxComp = max(maxComp,getSize(a));
            n--;
        }
        cout<< n << " "<< maxComp<<"\n";
    }
 
}