#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    ll n;
    cin>>n;
    ll tot = 1<<n;
    vector<vector<ll>> adj(tot+1);
    vector<ll> currentEdge(tot+1);

    for(int i = 0; i<tot; i++){
        ll next = (i<<1) & ((1<<(n+1))-1);
        cout<<i<<" "<<next<<"\n";
        adj[i].push_back(next);
        adj[i].push_back(next+1);
    }

    stack<ll> st;
    st.push(0);
    string s = "";
    while(st.size()){
        ll cur = st.top();
        if(currentEdge[cur]< (ll) adj[cur].size()){
            st.push(adj[cur][currentEdge[cur]]);
            currentEdge[cur]++;
        }
        else{
            st.pop();
            s+=currentEdge[cur];
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<"\n";


}