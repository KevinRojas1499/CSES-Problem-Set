#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9+5, mxN = 3e5;
ll sparse[mxN][20];


int main(){
    ll n,q,a,b;
    cin>>n>>q;
    vector<ll> x(n);
    for(int i = 0; i<n; i++) {
        cin>>x[i];
        sparse[i][0] = x[i];
    }

    for (int j = 1; j < 20; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            sparse[i][j] = min(sparse[i][j-1],sparse[i+(1 << (j-1))][j-1]);
        }
    }
    for(int i = 0; i<q; i++){
        cin>>a>>b;
        a--;b--;
        ll p = log2(b-a+1);
        cout<<min(sparse[a][p],sparse[b-(1<<p)+1][p])<<"\n";
    }
}