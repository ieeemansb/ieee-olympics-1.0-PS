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
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N = 200005;
#define M 1000000007
#define double long double
#define BINF 1000000000000001
const int minN = 1e7 + 5;
#define init(arr,val) memset(arr,val,sizeof(arr))
#define deb(x) cout << #x << " " << x << "\n";
const int LG = 22;

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
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      if(s[0] == s[s.length() - 1]){
        cout << -1 << endl;
      }else{
        cout << s << endl;
      }
    }


return 0;
}
