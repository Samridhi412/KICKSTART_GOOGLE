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
#define inf 9223372036854775807LL 
#define MAX 2505
// ll ans=INT_MAX;
// ll count=0;
ll n,m;
vector<vector<ll>> prefix(MAX+1,vector<ll>(MAX+1,-1));
vector<vector<ll>> suffix(MAX+1,vector<ll>(MAX+1,-1));
vector<ll> str(MAX+1);
vector<ll> keyboard(MAX+1);
ll mincosttyping(ll i,ll j,vector<vector<ll>>& dp){
	
	// count++;
	if(i==n){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll ans=inf;
	if(prefix[j][str[i]]!=-1){
		ll cost=abs(j-prefix[j][str[i]]);
		ans=min(ans,cost+mincosttyping(i+1,prefix[j][str[i]],dp));
		
	}
	if(suffix[j][str[i]]!=-1){
		ll cost=abs(j-suffix[j][str[i]]);
		ans=min(ans,cost+mincosttyping(i+1,suffix[j][str[i]],dp));
	}
	return dp[i][j]=ans;
}
void solve(){
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>str[i];
	}
	cin>>m;
	for(ll i=0;i<m;i++){
		cin>>keyboard[i];
	}
	ll mx=*max_element(keyboard.begin(),keyboard.end());
	for(ll i=0;i<m;i++){
		for(ll j=0;j<=mx;j++){
			prefix[i][j]=-1;
			suffix[i][j]=-1;
		}
	}
	for(ll i=0;i<m;i++){
		prefix[i][keyboard[i]]=i;
		suffix[i][keyboard[i]]=i;
	}
	for(ll j=0;j<=mx;j++){
		ll last=-1;
		for(ll i=0;i<m;i++){
			
			if(prefix[i][j]!=-1){
				last=prefix[i][j];
			}
			prefix[i][j]=last;
		}
		last=-1;
		for(ll i=m-1;i>=0;i--){
			
			if(suffix[i][j]!=-1){
				last=suffix[i][j];
			}
			suffix[i][j]=last;
		}
	}
	ll ans=inf;
	vector<vector<ll>> dp(n,vector<ll>(m,-1));
	for(ll j=0;j<m;j++){
		ans=min(ans,mincosttyping(0,j,dp));
	}
	cout<<ans<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}