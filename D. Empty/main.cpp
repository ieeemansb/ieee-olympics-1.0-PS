#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;

		stack<char> stk;

		int n = str.size();

		for(int i=0;i<n;i++)
		{
			if(stk.empty()) stk.push(str[i]);
			else
			{
				if(str[i] == stk.top()) stk.pop();
				else stk.push(str[i]);
			}
		}


		if(stk.empty()) cout<<"EMPTY"<<endl;
		else
		{
			string res = "";
			while(!stk.empty()){
				res = res + stk.top();
				stk.pop();
			}
			reverse(res.begin(),res.end());
			cout<<res<<"\n";
		}

	}
}
