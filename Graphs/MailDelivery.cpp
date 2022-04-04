#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    ll n,m,a,b;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<ll> currentEdge(n+1);
    map<pair<ll,ll>,bool> used;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool possible = true;
    for(int i = 1; i<=n; i++){
        if(adj[i].size()%2 != 0){
            possible = false;
            break;
        }
    }
    vector<bool> seen(n+1,false);
    queue<ll> q;
    q.push(1);
    seen[1] = true;
    while(q.size()){
        ll cur = q.front();
        q.pop();
        for(auto v : adj[cur]){
            if(!seen[v]){
                q.push(v);
                seen[v] = 1;
            }
        }
    }
    for(int i = 1; i<=n ; i++){
        if(!seen[i] && adj[i].size() > 0) {
            possible = false;
            break;
        }
    } 
    if(possible){
        vector<ll> res;
        stack<ll> st;
        st.push(1);
        while(st.size()){
            ll cur = st.top();
            if(currentEdge[cur] < (ll) adj[cur].size()){
                ll neigh = adj[cur][currentEdge[cur]];
                if(used[{cur,neigh}]){
                    currentEdge[cur]++;
                }
                else{
                    st.push(neigh);
                    currentEdge[cur]++;
                    used[{cur,neigh}] = used[{neigh,cur}] = 1;
                }
            }
            else{
                res.push_back(cur);
                st.pop();
            }
        }
        reverse(res.begin(),res.end());
        for(auto u : res){
            cout<< u<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

    

}