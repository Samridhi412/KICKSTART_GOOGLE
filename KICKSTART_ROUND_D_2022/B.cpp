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
	ll suma=0,sumb=0;
	ll n;
	cin>>n;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		suma+=a[i];
	}
	ll m;
	cin>>m;
	vector<ll> b(m+1);
	for(int i=1;i<=m;i++){
		cin>>b[i];
		sumb+=b[i];
	}
	ll k;
	cin>>k;
	ll dpa[n+1],dpb[m+1];
	memset(dpa,0,sizeof(dpa));
	memset(dpb,0,sizeof(dpb));
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=i,len=n-1;j<=n;j++,len--){
			sum+=a[j];
			dpa[len]=max(dpa[len],suma-sum);
		}
	}
	dpa[n]=suma;
	for(int i=1;i<=m;i++){
		long long sum=0;
		for(int j=i,len=m-1;j<=m;j++,len--){
			sum+=b[j];
			dpb[len]=max(dpb[len],sumb-sum);
		}
	}
	dpb[m]=sumb;
	ll max_sum=0;
	for(int i=0;i<=k;i++){
		if(i<=n&&k-i<=m)max_sum=max(max_sum,dpa[i]+dpb[k-i]);
	}
	cout<<max_sum<<endl;
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