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

ll n,p;


ll binary_search(ll count, FenwickTree &ft){
    ll a = 1, b = n;
    ll ans = n;
    while(a<=b){
        ll c = a +(b-a)/2;
        if(ft.rsq(c)>= count){
            ans = c;
            b = c-1;
        }
        else {
            a = c+1;
        }
    }
    return ans;
}


int main() {
    cin>>n;
    vector<ll> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];
    FenwickTree ft(n);
    for(int i = 0; i<n; i++) ft.add(i+1,1);

    for(int i = 0; i<n; i++) {
        cin>>p;
        ll idx = binary_search(p,ft);
        cout<<x[idx-1]<<" ";
        ft.add(idx,-1);
    }
    
}