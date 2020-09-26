#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll current = 1;
    for (int i = 0; i < n/2; ++i)
    {
        current *= a[i];
        current %= MOD;
    }
    ll answer = current;
    for (int i = 1  ; i <= (n+1)/2; ++i)
    {
        current *= modinv(a[i-1], MOD);
        current %= MOD;
        current *= a[n / 2 + i - 1];
        current %= MOD;
        answer += current;
        answer %= MOD;
    }
    cout << answer << endl;
}
