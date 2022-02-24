#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<pair<ll,ll>> times(n);
	vector<tuple<ll,ll,ll>> ids(2*n);
	for(int i = 0; i<n; i++){
		cin>>times[i].first>>times[i].second;
		ids[2*i] = {times[i].first,0,i};
		ids[2*i+1] = {times[i].second,1,i};
	}
	sort(ids.begin(),ids.end());
	vector<ll> rooms(n);
	set<ll> free;
	ll max = 1;
	free.insert(1);
	
	for(int i = 0; i<2*n; i++){
		ll curId = get<2>(ids[i]);
		if( get<1>(ids[i]) ){
			free.insert(rooms[curId]);
		}
		else{
			if(free.size()>0){
				auto it  = free.begin();
				rooms[curId] = *it;
				free.erase(it);
			}
			else{
				max++;
				rooms[curId] = max; 
			}
		}
	}
	cout<<max<<"\n";
	for(int i = 0;i<n; i++){
		cout<<rooms[i]<< " ";
	}

}
