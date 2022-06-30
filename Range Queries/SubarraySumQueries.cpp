#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18;

struct Data {
    ll sum, prefix, suffix, best;
};

class SegmentTree {
    public : 
        vector<Data> st;

        Data make_data(ll a) {
            Data d;
            d.sum = a;
            d.best = d.suffix = d.prefix = max(0ll,a);
            return d;
        }

        SegmentTree(vector<ll> a) {
            st.assign(a.size()*4,make_data(0));
            build(a,1,0,a.size()-1);
        }

        Data combine(Data a, Data b) {
            if(a.sum == INF) return b;
            if(b.sum == INF) return a;
            Data c;
            c.sum = a.sum+b.sum;
            c.prefix = max(a.prefix,a.sum+b.prefix);
            c.suffix = max(a.suffix+b.sum, b.suffix);
            c.best = max(a.best,max(b.best,a.suffix+b.prefix));
            return c;
        }

        void build(vector<ll> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = make_data(a[tl]);
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }

        Data query(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return make_data(INF);
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return combine(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = make_data(val);
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }
};

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,q,a,b;
    cin>>n>>q;
    vector<ll> x(n), l(n), r(n);
    for(int i = 0; i<n; i++) {
        cin>>x[i];
    }
    SegmentTree st(x);
    while(q--){
        cin>>a>>b;
        a--;
        st.update(1,0,n-1,a,b);
        cout<<st.query(1,0,n-1,0,n-1).best<<"\n";
    }
}