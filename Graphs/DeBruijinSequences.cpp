#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    ll n;
    cin>>n;
    n--;
    if(n == 0){
        cout<<"01\n";
        return 0;
    }
    ll tot = 1<<n;
    vector<vector<ll>> adj(tot+1);
    vector<ll> currentEdge(tot+1);
    for(int i = 0; i < tot; i++){
        ll next = i & ~(1<<(n-1));
        next = next<<1;
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
            s+= to_string(cur & 1);
        }
    }
    for(int i = 0; i<n-1; i++) s+= '0';
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
}
