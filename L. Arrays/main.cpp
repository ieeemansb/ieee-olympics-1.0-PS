#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);

using namespace std;

const int maxn = (int)1e6 + 100;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7;
const double pi = acos(-1.0);
#define inf mod

typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> Vll;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;
int n, m, k, a[maxn], b[maxn], c[maxn], l[4], r[4];
inline int sum(int a, int b){
    a += b;
    if(a >= m) a -= m;
    if(a < 0) a += m;
    return a;
}
inline int mult(int a, int b){
    return a * 1ll * b % m;
}
void solve(){
  cin >> n >> m >> k;
  forn(i, 1, n) cin >> a[i] >> b[i] >> c[i];
  forn(i, 1, 3) cin >> l[i] >> r[i];
  forn(x, l[1], min(r[1], l[1] + m - 1))
    forn(y, l[2], min(r[2], l[2] + m - 1))
      forn(z, l[3], min(r[3], l[3] + m - 1)){
        int cnt = 0;
        forn(i, 1, n){
          if(!sum(sum(mult(a[i], x), mult(b[i], y)), m - mult(c[i], z)))
            cnt++;
          if(cnt > k) break;
        }
        if(cnt == k){
          cout << x << " "  << y << " " << z << endl;
          exit(0);
        }
      }
  puts("-1");
}
main () {
  int t = 1;
  //scanf("%d", &t);
  while(t--)
    solve();
}
