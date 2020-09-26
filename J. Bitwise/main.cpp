#include <bits/stdc++.h>
using namespace std;
#define int long long int
mt19937 rng(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 1000000007
#define double long double
#define BINF 10000000000001
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 5000004
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

int a[N];

#undef int
int main() {
#define int long long int
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout);
#endif


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int F[(1LL << 19) + 5];
        init(F, -1);

        for(int i = 1; i <= n; i++)
            F[i] = a[i];

        for (int i = 0; i < 17; ++i) {
            for (int j = 0; j < (1 << 17); ++j) {
                if ((j & (1 << i)) > 0){
                    F[j] = max(F[j ^ (1 << i)], F[j]);
                }
            }
        }

        int Q[n + 1];

        int mask = (1LL << 17) - 1;
        for(int i = 1; i <= n; i++){
            int val = -1;
            if(F[mask ^ i] != -1) val = a[i] + F[mask ^ i];
            Q[i] = val;
        }

        int q;
        cin >> q;
        while(q--){
            int ind;
            cin >> ind;
            if(ind > n){
                while(1){

                }
            }
            cout << Q[ind] << endl;
        }
    }


return 0;
}
