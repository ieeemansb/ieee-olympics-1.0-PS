	#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;

const ll INF = 1e12;
const ll N =(1e5+5); // TODO : change value as per problem
const ll M = (3e5+5);
const ll MOD = 1e9+7;
vll graph[N];int U[M],V[M];//edge list representation of input graph
vll tree[N];//Bridge Tree formed from the given graph
bool isbridge[M]; // if i'th edge is a bridge edge or not
int vis[N],arr[N],T,cmpno;//supporting stuff
queue<int> Q[N];
int nice[N];
int adj(int u,int e){
	return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge)//mark bridges
{
	int dbe = arr[u] = T++;
	vis[u]=1;
	for(int i=0;i<graph[u].size();i++)
	{
		int e = graph[u][i];
		int w = adj(u,e);
		if(!vis[w])
			dbe = min(dbe,dfs0(w,e));
		else if(e!=edge)
			dbe = min(dbe,arr[w]);
	}
	if(dbe == arr[u] && edge!=-1)
		isbridge[edge]=true;
	return dbe;
}
void dfs1(int v)	//Builds the tree with each edge a bridge from original graph
{
	int currcmp = cmpno; // current component no.
	Q[currcmp].push(v);// A different queue for each component, coz during bfs we shall go to another component (step of dfs) and then come   back to this one and continue our bfs
	vis[v]=1;
	nice[v] = currcmp;
	while(!Q[currcmp].empty()) //bfs. Exploring all nodes of this  component
	{
		int u = Q[currcmp].front();
		Q[currcmp].pop();
		for(int i=0;i<graph[u].size();i++)
		{
			int e = graph[u][i];
			int w = adj(u,e);
			if(vis[w])continue;
			nice[w] = currcmp;
			if(isbridge[e])		//if the edge under consideration is bridge and other side is not yet explored, go there (step of dfs)
			{
				cmpno++;
				tree[currcmp].push_back(cmpno);
				tree[cmpno].push_back(currcmp);
				dfs1(w);
			}
			else	//else continue with our bfs
			{
				Q[currcmp].push(w);
				vis[w]=1;
			}
		}
	}
}
void solve(){
	int n,m;
	cin >> n >> m;
	int a,b;
	cin >> a >> b;
	a--;
	b--;
	for(int i= 0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		U[i] = v;
		V[i] = u;
		graph[u].pb(i);
		graph[v].pb(i);
	}
	dfs0(0,-1);
	 memset(vis,0,sizeof(vis));
	 dfs1(0);

	 int u = nice[a];
	 int v = nice[b];
	 queue<int> q;
	 vector<int> dis(cmpno+1,-1);
	 dis[u] =0;
	 q.push(u);
	 while(!q.empty()){
	 	int p = q.front();
	 	q.pop();
	 	for(auto g:tree[p]){
	 		if(dis[g] == -1){
	 			dis[g] =  dis[p] + 1;
	 			q.push(g);
	 		}
	 	}
	 }
	 cout << dis[v] << endl;
}
signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);

     ll tt=1;
     // cin >> tt;
    while(tt--){
        solve();
    }
}
