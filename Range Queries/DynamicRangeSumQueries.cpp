#include <bits/stdc++.h>
#define ll long long
#define LSOne(S) ((S) & -(S))

using namespace std;

class FenwickTree {
    public:
        ll n;
        vector<ll> ft;

        FenwickTree(ll n){
            this->n = n+1;
            ft.assign(n+1,0);
        }

        FenwickTree(vector<ll> a) : FenwickTree(a.size()){
            for(int i = 0; i<n; i++) add(i+1,a[i]);
        }

        ll rsq(ll j) {
            ll res = 0;
            for(; j > 0 ; j-= LSOne(j)){
                //Vamos quitando u nbit a la vez
                res+=ft[j];
            }
            return res;
        }

        ll rsq(ll i, ll j){
            return rsq(j)-rsq(i-1);
        }

        void add(ll idx, ll delta) {
            for(; idx < n; idx+= LSOne(idx)){
                ft[idx] += delta;
            }
        }
};

int main () {
    ll n,q,a,b,c;
    cin>>n>>q;
    vector<ll> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    FenwickTree ft(x);
    while(q--){
        cin>>a>>b>>c;
        if(a == 2){
            cout<<ft.rsq(b,c)<<"\n";
        }
        else{
            ft.add(b,c-x[b-1]);
            x[b-1] = c;
        }
    }
}