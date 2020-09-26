#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define eps 1e-9
const int MOD = 1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
ll POWER[65];
ll power(ll a, ll b) {ll ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=MOD) ret%=MOD;if(a>=MOD) a%=MOD;b>>=1;}return ret;}
ll inv(ll x) {return power(x,MOD-2);}
void precompute() {
	POWER[0]=1;
	for(int i=1;i<63;i++) POWER[i]=POWER[i-1]<<1LL;
}
int main() {
	// freopen("TASK.in","r",stdin);freopen("TASK.out","w",stdout);
	precompute();
	ll n,k;
	cin>>n>>k;
	assert(n>=1LL and n<=1000000000000000000LL);
	assert(k>=0 and k<=9);
	vector<int> v;
	while(n) {
		v.pb(n%10);
		n/=10;
	}
	reverse(all(v));
	for(int i=0;i<sz(v) and k--;i++) {
		if(v[i]==9) {
			k++;
			continue;
		}
		else v[i]=9;
	}
	for(auto it:v) cout<<it;
	cout<<endl;
	return 0;
