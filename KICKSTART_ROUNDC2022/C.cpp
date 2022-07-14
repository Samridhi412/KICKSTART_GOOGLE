#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
class Ants{
public:
	ll pos;
	ll dir;
	ll index;
	Ants(ll pos,ll dir,ll index){
		this->pos=pos;
		this->dir=dir;
		this->index=index;
	}
};
bool cmp(Ants a1,Ants a2){
	return a1.pos<a2.pos;
}
void solve(){
	ll n,l;
	cin>>n>>l;
	// vector<int> x(n);
	// vector<int> dir(n);
	vector<Ants> ants;
	vector<pair<ll,ll>> events;
	for(ll i=0;i<n;i++){
		ll x,dir;
		cin>>x;
		cin>>dir;
		Ants a(x,dir,i+1);
		// a.pos=x;
		// a.dir=dir;
		// a.index=i+1;
		ants.push_back(a);
		if(dir==0){
			events.push_back({x,0});
		}
		else{
			events.push_back({l-x,1});
		}
	}
	sort(ants.begin(),ants.end(),cmp);
	sort(events.begin(),events.end());
	ll l1=0;
	ll r=n-1;
	vector<pair<ll,ll>> order;
	for(ll i=0;i<n;i++){
		if(events[i].second==1){
			order.push_back({events[i].first,ants[r--].index});
		}
		else{
			order.push_back({events[i].first,ants[l1++].index});
		}
	}
	sort(order.begin(),order.end());
	for(ll i=0;i<n;i++){
		cout<<order[i].second<<" ";
	}
	cout<<endl;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}