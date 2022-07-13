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
// ll ans=INT_MAX;
long long count=0;
ll mincosttyping(ll i,ll j,vector<vector<ll>>& dp,ll n,vector<vector<ll>>& prefix,vector<vector<ll>>& suffix,vector<ll> str){
	
	count++;
	if(i==n){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll ans=INT_MAX;
	if(prefix[j][str[i]]!=-1){
		ll cost=abs(j-prefix[j][str[i]]);
		ans=min(ans,mincosttyping(i+1,prefix[j][str[i]],dp,n,prefix,suffix,str)+cost);
		
	}
	if(suffix[j][str[i]]!=-1){
		ll cost=abs(j-suffix[j][str[i]]);
		ans=min(ans,mincosttyping(i+1,suffix[j][str[i]],dp,n,prefix,suffix,str)+cost);
	}
	return dp[i][j]=ans;
}
void solve(){
	ll n,m;
	cin>>n;
	vector<ll> str(n);
	for(ll i=0;i<n;i++){
		cin>>str[i];
	}
	cin>>m;
	vector<ll> keyboard(m);
	for(ll i=0;i<m;i++){
		cin>>keyboard[i];
	}
	ll mx=*max_element(keyboard.begin(),keyboard.end());
	vector<vector<ll>> prefix(m,vector<ll>(mx+1,-1)),suffix(m,vector<ll>(mx+1,-1));
	for(ll i=0;i<m;i++){
		prefix[i][keyboard[i]]=i;
		suffix[i][keyboard[i]]=i;
	}
	for(ll j=1;j<=mx;j++){
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
	// cout<<"///////////////"<<endl;
	// for(int i=0;i<m;i++){
	// 	for(int j=1;j<=mx;j++){
	// 		cout<<prefix[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"///////////"<<endl;
	// for(int i=0;i<m;i++){
	// 	for(int j=1;j<=mx;j++){
	// 		cout<<suffix[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"//////////////"<<endl;
	ll ans=INT_MAX;
	vector<vector<ll>> dp(n,vector<ll>(m,-1));
	for(ll j=0;j<m;j++){
		ans=min(ans,mincosttyping(0,j,dp,n,prefix,suffix,str));
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
		cout<<"////"<<endl;
		cout<<count<<endl;
		count=0;
	}
	return 0;
}