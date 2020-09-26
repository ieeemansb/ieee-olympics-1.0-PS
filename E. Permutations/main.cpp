#include<iostream>
using namespace std;
long long int mod = 1e9 + 7;
long long int dp[4003][2002][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, kai;
	cin >> num >> kai;
	dp[0][0][0] = 1;
	int pt = 0;
	for (int i = 0; i < kai * 2; i++){
		int t = 0;
		int nx, ny;
		if (i < kai)nx = i, ny = i + kai;
		else nx = i, ny = i - kai;
		while(true){
			if (nx >= num || ny >= num){
				break;
			}
			t++;
			if (nx < ny){
				nx += kai * 2;
			}else{
				ny += kai * 2;
			}
		}
		for (int j = 0; j < t; j++){
			for (int k = 0; k <= num; k++){
				dp[pt + 1][k][0] += dp[pt][k][0] + dp[pt][k][1];
				dp[pt + 1][k + 1][1] += dp[pt][k][0];
				dp[pt + 1][k][0] %= mod;
				dp[pt + 1][k + 1][1] %= mod;
			}
			pt++;
		}
		for (int k = 0; k <= num; k++){
			dp[pt][k][0] += dp[pt][k][1];
			dp[pt][k][0] %= mod;
			dp[pt][k][1] = 0;
		}
	}
	long long int ans = 0;
	long long int now = 1;
	for (int i = num; i >= 0; i--){
		if (i % 2 == 0){
			ans += dp[pt][i][0] * now;
		}else{
			ans += mod - dp[pt][i][0] * now % mod;
		}
		ans %= mod;
		now *= (num - i + 1);
		now %= mod;
	}
	cout << ans;
}
