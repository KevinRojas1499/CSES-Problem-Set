#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int sz = 200005;
ll a[sz], bit[sz], n, k;
map<ll, ll> compressed, decompress;

ll psum(ll x, ll sum = 0){
	for (; x > 0; x -= x & -x){
		sum += bit[x]; 
	}
	return sum;
}
void add(ll x, ll val){
	for (; x < sz; x += x & -x){
		bit[x] += val;
	}
}

ll getMedian(){
	ll aa = 1, b = n;
	ll mid = (k+1)/2;
	while(aa<=b){
		ll c = aa+(b-aa)/2;
		if(psum(c) >= mid && psum(c - 1)<mid) return decompress[c];
		if(psum(c)<mid){
			aa = c+1;
		}
		else{
			b = c-1;
		}
	}
	return decompress[aa];
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	memset(bit,0,sizeof bit);
	
	for(int i = 0; i<n; i++){
		cin>>a[i];
		compressed[a[i]] = 0;
	}
	ll t = 1;
	for(auto b: compressed){
		compressed[b.first] = t;
		decompress[t] = b.first;
		t++;
	}
	ll cost = 0;
	for(int i = 0; i<k; i++){
		add(compressed[a[i]],1);
	}
	ll oldMedian = getMedian();
	for(int i = 0; i<k; i++){
		cost+=abs(oldMedian-a[i]);
	}
	cout<<cost<<" ";
	for(int i = k; i<n; i++){
		add(compressed[a[i]],1);
		add(compressed[a[i-k]],-1);
		ll median = getMedian();
		add(compressed[a[i]],-1);
		add(compressed[a[i-k]],1);
		ll below = psum(compressed[median]-1);//Numero de menores a la mediana
		ll equalMedian = psum(compressed[median])-below;
		ll up = k-equalMedian-below;
		add(compressed[a[i]],1);
		add(compressed[a[i-k]],-1);
		cost+=below*(median-oldMedian);
		cost+=equalMedian*(median>oldMedian? oldMedian-median: median-oldMedian);
		cost+=up*(oldMedian-median);
		cost+=abs(median-a[i]);
		cost-=abs(median-a[i-k]);
		oldMedian = median;
		cout<<cost<<" ";
	}
		
	
	
}
