#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e10;

class SegmentTree {
    public : 
        vector<ll> st;

        SegmentTree(vector<ll> a) {
            st.assign(a.size()*4,0);
            build(a,1,0,a.size()-1);
        }

        void build(vector<ll> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = a[tl];
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = min(st[2*v],st[2*v+1]);
            }
        }

        ll getMin(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return INF;
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return min(getMin(2*v,tl,tm,l,min(r,tm)),getMin(2*v+1,tm+1,tr, max(l,tm+1),r));
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = val;
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = min(st[2*v],st[2*v+1]);
            }
        }

};

int main () {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
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
            cout<<st.getMin(1,0,n-1,b-1,c-1)<<endl;
        }
    }
}