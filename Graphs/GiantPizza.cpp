#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m,a,b;

vector<vector<ll>> adj, requirements;
vector<ll> current, status;
const ll NOTSEEN = 0, USED = 1, CANNOTUSE = -1, EXPLORED = 2, EXPLOREDCANTUSE = -2;

ll neg(ll aa){
    if(aa<=m){
        return aa+m;
    }
    else{
        return aa-m;
    }
}

bool dfs(ll u){
    if(status[u] == CANNOTUSE || status[u] == EXPLOREDCANTUSE) return false;
    if(status[u] == USED || status[u] == EXPLORED) return true;
    status[u] = EXPLORED;
    status[neg(u)] = EXPLOREDCANTUSE;
    current.push_back(u);
    bool possible = true;
    for(auto v : adj[u]){
        possible &= dfs(v);
    }
    return possible;
}


bool solve(ll u){
    if(u == n) return true;
    for(auto req : requirements[u]){
        if(status[neg(req)] == NOTSEEN){
            //Can add req
            if(dfs(req)){
                //Add it
                vector<ll> toRemove;
                for(auto v : current){
                    status[v] = USED;
                    status[neg(v)] = CANNOTUSE;
                    toRemove.push_back(v);
                }
                current.clear();
                if(solve(u+1)) return true;
                for(auto v : toRemove){
                    status[v] = NOTSEEN;
                    status[neg(v)] = NOTSEEN;
                }
            }
            else{
                for(auto v : current){
                    status[v] = NOTSEEN;
                    status[neg(v)] = NOTSEEN;
                }
                current.clear();
            } 
        }
        if(status[req] == USED){
            if(solve(u+1)) return true;
        }
    }
    return false;
}


int main(){
    cin>>n>>m;
    adj.resize(2*m+1);
    status.assign(2*m+1,NOTSEEN);
    requirements.resize(n+1);
    //1 ... n include n+1... 2n dont include
    char c1,c2;
    for(int i = 0; i<n; i++){
        cin>>c1>>a>>c2>>b;
        if(c1 == '-') a = neg(a);
        if(c2 == '-') b = neg(b);
        adj[neg(a)].push_back(b);
        adj[neg(b)].push_back(a);
        requirements[i].push_back(a);
        requirements[i].push_back(b);
    }

    if( solve(0) ) {
        for(int i = 1; i<=m ;i++){
            if(status[i] == USED){
                cout<<"+ ";
            }
            else{
                cout<<"- ";
            }
        }
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

}