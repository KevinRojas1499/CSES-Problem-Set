#include <bits/stdc++.h>
#define ll long long 
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


bool comp(pair<ll,ll> p1, pair<ll,ll> p2){
	if(p1.first!=p2.first) return p1.first<p2.first;
	else{
		return p1.second>p2.second;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,x,y;
	cin>>n;
	vector<pair<ll,ll>> points(n);
	vector<ll> containsOne(n,0);
	vector<ll> isContainedIn(n,0);
	map<pair<ll,ll>,ll> id;
	indexed_set endPoints;
	indexed_set processed;
	for(int i = 0; i<n ;i++){
		cin>>x>>y;
		points[i] = {x,y};
		id[points[i]] = i;
		if( endPoints.find(make_pair(y,0ll)) == endPoints.end()){
			endPoints.insert({y,0});
		}
		else{
			auto it = endPoints.upper_bound({y,n});
			it--;
			pair<ll,ll> cur = *it;
			endPoints.insert({y,cur.second+1});
		}
	}
	
	sort(points.begin(),points.end(),comp);

	
	ll m = -1;
	for(int i = 0; i<n;i++){
		auto upper = endPoints.lower_bound({points[i].second,0});
		isContainedIn[id[points[i]]] = processed.size()-processed.order_of_key({points[i].second,0});
		y = points[i].second;
		if( processed.find(make_pair(y,0)) == processed.end()){
			processed.insert({y,0});
		}
		else{
			auto it = processed.upper_bound({y,n});
			it--;
			pair<ll,ll> cur = *it;
			processed.insert({y,cur.second+1});
		}
		endPoints.erase(upper);
		

		containsOne[id[points[i]]] = endPoints.order_of_key({y+1,0});

		
		m = max(m,points[i].second);
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
