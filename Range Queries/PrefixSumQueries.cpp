#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e10;

struct Data {
    ll sum,prefix;
};

class SegmentTree {
    public : 
        vector<Data> st;

        Data make_data(ll a) {
            Data c;
            c.sum = a;
            c.prefix = max(a,0ll);
            return c;
        }

        SegmentTree(vector<ll> a) {
            st.assign(a.size()*4,make_data(0));
            build(a,1,0,a.size()-1);
        }

        Data combine(Data a, Data b) {
            Data c;
            if(a.sum == -INF) return b;
            if(b.sum == -INF) return a;
            c.sum = a.sum+b.sum;
            c.prefix = max(a.prefix,a.sum+b.prefix);
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

        Data getMax(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return make_data(-INF);
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return combine(getMax(2*v,tl,tm,l,min(r,tm)),getMax(2*v+1,tm+1,tr, max(l,tm+1),r));
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
    ll n,q,a,b,c;
    cin>>n>>q;
    vector<ll> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    SegmentTree st(x);
    while(q--){
        cin>>a>>b>>c;
        if(a == 1) {
            st.update(1,0,n-1,b-1,c);
        }
        else {
            cout<<st.getMax(1,0,n-1,b-1,c-1).prefix<<endl;
        }
    }
}