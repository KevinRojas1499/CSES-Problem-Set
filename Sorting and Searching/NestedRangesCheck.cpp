#include <bits/stdc++.h>
#define ll long long 
using namespace std;



int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	ll n,x,y;
	cin>>n;
	vector<pair<ll,ll>> points(n);
	vector<ll> containsOne(n,0);
	vector<ll> isContainedIn(n,0);
	map<pair<ll,ll>,ll> id;
	map<ll,ll> minn;
	multiset<ll> endPoints;
	for(int i = 0; i<n ;i++){
		cin>>x>>y;
		points[i] = {x,y};
		id[points[i]] = i;
		points[i] = {x,-y};
		if(minn.find(y) == minn.end()){
			minn[y] = x;
		}
		else{
			minn[y] = min(minn[y],x);
		}
		endPoints.insert(y);
	}
	
	sort(points.begin(),points.end());
	for(int i = 0; i<n; i++){
		points[i].second = -points[i].second;
	}

	ll m = -1;
	for(int i = 0; i<n-1;i++){
		auto upper = endPoints.lower_bound(points[i].second);
		if(points[i].second <= m){
			isContainedIn[id[points[i]]] = 1;
		}
				
		endPoints.erase(upper);
		auto lower = endPoints.lower_bound(points[i].second);
		if(*lower == points[i].second){
			containsOne[id[points[i]]] = 1;
		}
		else if(lower != endPoints.begin()){
			lower--;
			if(*lower <= points[i].second){
				containsOne[id[points[i]]] = 1;
			}
		}
		m = max(m,points[i].second);
	}
	
	if(m>=points[n-1].second){
		isContainedIn[id[points[n-1]]] = 1;
	}
	for(auto a: containsOne){
		cout<<a<<" ";
	}
	cout<<"\n";
	for(auto a: isContainedIn){
		cout<<a<<" ";
	}
	cout<<"\n";


		
}
