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
void solve(){
	ll n,x,y;
	cin>>n>>x>>y;
	ll total=n*(n+1)/2;
	if(total%(x+y)){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		cout<<"POSSIBLE"<<endl;
		ll sum=x*total/(x+y);
		vector<int> s1,s2;
		for(int i=n;i>=1;i--){
			if(i<=sum){
				s1.push_back(i);
				sum-=i;
			}
			else{
				s2.push_back(i);
			}
		}
		cout<<s1.size();
		for(auto x:s1){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	
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