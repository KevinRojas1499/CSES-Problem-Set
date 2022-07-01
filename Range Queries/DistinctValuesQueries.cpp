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

const ll mxN = 3e5;
ll n,q;
vector<ll> x;
vector<vector<pair<ll,ll>>> queries(mxN);
map<ll,ll> firstAppearance;

int main () {
    cin>>n>>q;
    x.resize(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    for(int i = 0; i<q; i++){
        ll a,b;
        cin>>a>>b;
        queries[a].push_back({b,i});
    }
    FenwickTree ft(n);
    vector<ll> sol(q);
    for(int i = n; i>=1; i--){
        ll cur = x[i-1];
        if(firstAppearance.find(cur) != firstAppearance.end()) {
            ft.add(firstAppearance[cur], -1);
        }
        firstAppearance[cur] = i;
        ft.add(i,1);
        for(auto [querie, pos] : queries[i]){
            sol[pos] = ft.rsq(querie);
        }
    }
    for(auto s : sol) cout<<s<<"\n";

}


