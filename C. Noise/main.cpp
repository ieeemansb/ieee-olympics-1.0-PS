#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int l , r , s;
		cin >> l >> r >> s;
		l = (l - 1) / s + 1;
		r = r / s;
		if(l > r)
			cout << "-1 -1" << endl;
		else
			cout << l << " " << r << endl;
	}
}
