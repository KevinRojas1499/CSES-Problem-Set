#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll NEGINF = -1;

class SegmentTree {
    public : 
        vector<ll> st;

        SegmentTree(vector<ll>& a) {
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
                st[v] = max(st[2*v],st[2*v+1]);
            }
        }

        ll getMax(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return NEGINF;
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return max(getMax(2*v,tl,tm,l,min(r,tm)),getMax(2*v+1,tm+1,tr, max(l,tm+1),r));
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = val;
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = max(st[2*v],st[2*v+1]);
            }
        }

};

ll n;

ll findRoom(ll target, SegmentTree & st){
    ll a = 0, b = n-1;
    ll ans = 0;
    while(a<=b){
        ll c = a+(b-a)/2;
        ll m = st.getMax(1,0,n-1,0,c);
        if(m>= target){
            ans = c+1;
            b = c-1;
        }
        else {
            a = c+1;
        }
    }
    return ans;
}

int main () {
    ll q,b;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    SegmentTree st(a);
    while(q--){
        cin>>b;
        ll idx = findRoom(b,st);
        cout<<idx<<" ";
        if(idx > 0) st.update(1,0,n-1,idx-1,st.getMax(1,0,n-1,idx-1,idx-1)-b);
    }
    cout<<"\n";
}