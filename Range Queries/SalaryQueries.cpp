#include <bits/stdc++.h>
#define ll long long
#define LSOne(S) ((S) & -(S))
 
using namespace std;
 
 
map<ll,ll> compress;
vector<ll> decompress;
 
 
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
 
 
ll binary_search(ll targ, FenwickTree &ft){
    auto it = upper_bound(decompress.begin(),decompress.end(), targ);
    if(it == decompress.begin()) return 0;
    ll idx = it-decompress.begin()-1;
    // cout<<"para "<<targ<<" "<<idx<<" "<<ft.rsq(idx)<<"\n";
    return ft.rsq(idx);
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin>>n>>q;
    vector<ll> x(n);
    vector<ll> salaries;
    for(int i = 0; i<n; i++) {
        cin>>x[i];  
        salaries.push_back(x[i]);
    }
    vector<pair<char,pair<ll,ll>>> queries;
    for(int i = 0; i<q; i++){
        char a;
        ll b,c;
        cin>>a>>b>>c;
        queries.push_back({a,{b,c}});
        if(a == '!'){
            salaries.push_back(c);
        }
    }
    sort(salaries.begin(),salaries.end());
    salaries.erase(unique(salaries.begin(),salaries.end()),salaries.end());
    ll k = 1;
    decompress.resize(salaries.size()+1);
    for(auto c : salaries){
        compress[c] = k;
        decompress[k] = c;
        k++;
    }
    FenwickTree ft(k);
    for(int i = 0; i<n; i++){
        ft.add(compress[x[i]],1);
    }
    for(auto [a,b]: queries){
        if(a == '!') {
            auto [idx,p] = b;
            ft.add(compress[x[idx-1]],-1);
            ft.add(compress[p],1);
            x[idx-1] = p;
        }
        else {
            auto [c,d] = b;
            cout<<binary_search(d,ft)-binary_search(c-1,ft)<<"\n";
        }
    }
 
}