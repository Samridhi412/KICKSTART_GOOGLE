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
	ll n,m;
	cin>>n>>m;
	vector<int> regions(n);
	for(int i=0;i<n;i++){
		cin>>regions[i];
	}
	sort(regions.begin(),regions.end());
	double ans=0;
	for(int i=0;i<m-1;i++){
		ans+=regions[n-1-i];
	}
	ans+=(regions[(n-m+1)/2] + regions[(n-m)/2])/2.0;
	cout<<ans<<endl;
	
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