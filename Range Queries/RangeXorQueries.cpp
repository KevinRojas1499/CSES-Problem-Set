#include <bits/stdc++.h>
#define ll long long

using namespace std;

class SegmentTree {
    public : 
        vector<ll> st;

        SegmentTree(vector<ll> &a) {
            st.assign(a.size()*4,-1);
            build(a,1,0,a.size()-1);
        }
        
        ll combine(ll a, ll b){
            if(a == -1) return b;
            if(b == -1) return a;
            return a ^ b;
        }

        void build(vector<ll> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = a[tl];
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }

        ll xorSum(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return -1;
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return combine(xorSum(2*v,tl,tm,l,min(r,tm)),xorSum(2*v+1,tm+1,tr, max(l,tm+1),r));
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = val;
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
    vector<ll> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    SegmentTree st(x);
    while(q--){
        cin>>a>>b;
        cout<<st.xorSum(1,0,n-1,a-1,b-1)<<"\n";
    }
}