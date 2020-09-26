#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)
bool debug=true;

template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
	os<<ptt.first<<","<<ptt.second;
	return os;
}
template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
	os<<"{";
	for(int i=0;i<vt.size();i++){
		os<<vt[i]<<" ";
	}
	os<<"}";
	return os;
}
ll a,n,b;
//return log_b(a)
inline double log(ll a,ll b){
	return log10(a)/log10(b);
}
inline bool ok(ll x,ll n){
	long double v=floor(x*log(x,b)+log(a,b))+1;
	if(v>=n){
		return true;
	}else{
		return false;
	}
}
void solve(){
	//find first
	ll l=0,r=1e9;
	while(l<=r){
		ll m=(l+r)/2;
		if(ok(m,n)){
			r=m-1;
		}else{
			l=m+1;
//			r=m-1;
		}
	}

//	cout<<l<<endl;

	//find last
	ll l2=0,r2=1e9;
	while(l2<=r2){
		ll m=(l2+r2)/2;
		if(ok(m,n+1)){
			r2=m-1;
		}else{
			l2=m+1;
		}
	}

	cout<<l2-l<<endl;
}
int main(int argc,char* argv[]){
	while(cin>>a>>n>>b){
		solve();
	}
	return 0;
}
