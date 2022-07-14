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
	ll n;
	cin>>n;
	string str;
	cin>>str;
	bool isupper=false;
	bool islower=false;
	bool isdigit=false;
	bool isspeacial=false;
	for(int i=0;i<n;i++){
		if(str[i]=='@'||str[i]=='#'||str[i]=='&'||str[i]=='*')isspeacial=true;
		if('0'<=str[i]&&str[i]<='9')isdigit=true;
		if('a'<=str[i]&&str[i]<='z')islower=true;
		if('A'<=str[i]&&str[i]<='Z')isupper=true;
	}
	if(!isupper){
		str=str+'A';
	}
	if(!islower){
		str=str+'a';
	}
	if(!isdigit){
		str=str+'0';
	}
	if(!isspeacial){
		str=str+'@';
	}
	while(str.size()<7){
		str=str+'a';
	}
	cout<<str<<endl;
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