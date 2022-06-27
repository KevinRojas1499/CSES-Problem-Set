#include <bits/stdc++.h>
#define ll long long
#define LSOne(S) ((S) & -(S))

using namespace std;

class FenwickTree {
    public:
        ll n;
        vector<ll> ft;

        FenwickTree(ll nn){
            this->n = nn+1;
            ft.assign(nn+1,0);
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

class FenwickTree2D {
    public:
        vector<FenwickTree> ft;
        ll n,m;

        FenwickTree2D (ll nn, ll mm) {
            this->n = nn+1;
            this->m = mm+1;
            ft.assign(nn+1, FenwickTree(mm));
        }

        FenwickTree2D (vector<vector<ll>> a) : FenwickTree2D(a.size(),a[0].size()) {
            for(int i = 0; i< (ll) a.size(); i++){
                for(int j = 0; j< (ll) a[0].size(); j++){
                    add(i+1,j+1,a[i][j]);
                }
            }
        }

        ll queries(ll a, ll b){
            //Rectangulo con esquinas 1,1 y a ,b 
            ll sum = 0;
            for(; b > 0; b-=LSOne(b)){
                sum+= ft[b].rsq(a);
            }
            return sum;
        }

        ll range_queries(ll a, ll b, ll c, ll d) {
            //Rectangulo con columnas de a - b y filas de c -d
            return queries(d,c)+queries(b-1,a-1) - queries(b-1,c) - queries(d,a-1);
        }

        void add(ll a, ll b, ll delta){
            for(; a< n; a+=LSOne(a)){
                ft[a].add(b,delta);
            }
        }

};

int main () {
    ll n,q,b,d,e,f;
    char c;
    cin>>n>>q;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++){
            cin>>c;
            if(c == '*') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    FenwickTree2D ft2(a);
    while(q--){
        cin>>b>>d>>e>>f;
        pair<ll,ll> p1 = {b,d}, p2 = {e,f};
        if(p1> p2) swap(p1,p2);
        cout<< ft2.range_queries(p1.first,p1.second,p2.first,p2.second)<<"\n";
    }
}