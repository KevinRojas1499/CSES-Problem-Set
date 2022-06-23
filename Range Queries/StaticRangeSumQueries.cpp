#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n,q,c,d;
    cin>>n>>q;
    vector<ll> a(n),b(n+1);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        b[i+1] = b[i]+a[i];
    }
    while(q--){
        cin>>c>>d;
        cout<<b[d]-b[c-1]<<"\n";
    }
}