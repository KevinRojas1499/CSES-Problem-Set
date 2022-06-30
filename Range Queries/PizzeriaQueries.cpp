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

        ll combine(ll a, ll b) {
            if(a == INF) return b;
            if(b == INF) return a;
            return min(a,b);
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

        ll query(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return INF;
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return combine(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
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
    ll n,q,a,b,c;
    cin>>n>>q;
    vector<ll> x(n), l(n), r(n);
    for(int i = 0; i<n; i++) {
        cin>>x[i];
        r[i] = x[i]+i;
        l[i] = x[i]+n-i;
    }
    SegmentTree stDer(r), stIzq(l);
    while(q--){
        cin>>a;
        if(a == 1) {
            cin>>b>>c;
            b--;
            stDer.update(1,0,n-1,b,c+b);
            stIzq.update(1,0,n-1,b,c+n-b);
        }
        else {
           cin>>b;
           b--;
           ll costDer = stDer.query(1,0,n-1,b,n-1)-b;
           ll costIzq = stIzq.query(1,0,n-1,0,b)-(n-b);
           cout<<min(costDer,costIzq)<<"\n"; 
        }
    }
}