#include <bits/stdc++.h>
#define ll long long
#define LSOne(S) ((S) & -(S))

using namespace std;

class FenwickTree {
    public: 
        vector<ll> ft;
        ll n;

        FenwickTree(ll n) {
            this->n = n+1;
            ft.assign(n+1,0);
        }

        void add(ll pos, ll delta) {
            for(;pos<n; pos+=LSOne(pos)){
                ft[pos]+=delta;
            }
        }

        ll point_query(ll pos) {
            ll res = 0;
            for(; pos>0; pos-=LSOne(pos)){
                res+=ft[pos];
            }
            return res;
        }

        void range_update(ll l, ll r, ll delta){
            add(l,delta);
            if(r < n-1) add(r+1,-delta);
        }
};

int main () {
    ll n,q,a,b,c;
    cin>>n>>q;
    vector<ll> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    FenwickTree ft(n);
    while(q--){
        cin>>c;
        if(c == 2) {
            cin>>a;
            cout<<ft.point_query(a)+x[a-1]<<"\n";
        }
        else {
            cin>>a>>b>>c;
            ft.range_update(a,b,c);
        }
    }
}