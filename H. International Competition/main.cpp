#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll num;
	cin>>num;
	deque<int>dq;
	stack<int>st;
	for(int i=0; i<num; i++)
	{
		int x;
		cin>>x;
		st.push(x);
		dq.push_back(x);
	}
	while(!dq.empty() && !st.empty())
	{
		int a = st.top();
		int b = dq.front();
		if(a == b)
		{
			cout<<0<<" ";
			st.pop();
			dq.pop_front();
		}
		else if(a < b)
	    {
			cout<<1<<" ";
			st.pop();
		}
		else if(a > b)
		{
			cout<<2<<" ";
			dq.pop_front();
		}
	}
	return 0;
}
