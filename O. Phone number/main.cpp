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

int main(){

    int n;
    bool f=true;
    cin>>n;
    string s;
    for(int i=0 ; i<n ; i++){
        f=true;
        cin>>s;
        for(int j=0;j<10;j++){if(! isdigit( s[j] ) ) {cout<<"NO\n"; f=false; break;} }
        if(f){
            if(s[0]=='0' || s.size()!=10) cout <<"NO\n";
            else cout<<"YES\n";
        }
    }


}
