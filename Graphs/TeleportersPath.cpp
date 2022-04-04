#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n,m,a,b;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<ll> currentEdge(n+1), in(n+1);
    adj[0].push_back(1);
    in[1]++;
    adj[n].push_back(0);
    in[0]++;
    ll first = 0;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    bool possible = true;
    for(int i = 0; i<=n; i++){
        if((ll) adj[i].size() != in[i]){
            possible = false;
        }
    }
       
    
    vector<bool> seen(n+1);
    queue<ll> q;
    q.push(1);
    seen[1] = 1;
    while(q.size()){
        ll cur = q.front();
        q.pop();
        for(auto v : adj[cur]){
            if(!seen[v]){
                seen[v] = 1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i<=n; i++)
        if(!seen[i] && adj[i].size()) possible = false;

    if(possible){
        stack<ll> st;
        st.push(first);
        vector<ll> order;
        while(st.size()){
            ll cur = st.top();
            if(currentEdge[cur]< (ll) adj[cur].size()){
                st.push(adj[cur][currentEdge[cur]]);
                currentEdge[cur]++;
            }
            else{
                st.pop();
                order.push_back(cur);
            }
        }
        if(first == 0) order.pop_back();
        reverse(order.begin(),order.end());
        if(first == 0) order.pop_back();
        for(auto v : order){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
}