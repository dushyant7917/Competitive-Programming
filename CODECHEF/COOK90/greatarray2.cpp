#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int A[N];
int dp[N][2][2];

int inv(int x) {
	return n - x + 1;
}

bool satisfy(int a, int b, bool isUp) {
	if(isUp == 0) 		return a < b;
	else				return a > b;
}

void solve() {
	memset(dp, 0, sizeof(dp));
	int cntr, wow;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>A[i];

	if(n == 1) {
		cout<<0<<endl;
		return ;
	}

	if((n % 2) == 0) {
		for(int isUp = 0; isUp <= 1; isUp++) {
			if(satisfy(A[n/2], A[n/2 + 1], isUp))	dp[n/2][isUp][0] = 0;
			else									dp[n/2][isUp][0] = INT_MAX;

			if(satisfy(A[inv(n/2)], A[inv(n/2 + 1)], isUp))	dp[n/2][isUp][1] = 1;
			else									dp[n/2][isUp][1] = INT_MAX;
		}
		cntr = n/2 - 1;
		wow = 0;
	} else {
		if(A[n/2 + 1] < A[n/2] and A[n/2 + 1] < A[n/2 + 2])	dp[n/2 + 1][0][0] = 0, dp[n/2 + 1][0][1] = 1;
		else 												dp[n/2 + 1][0][0] = dp[n/2 + 1][0][1] = INT_MAX;

		if(A[n/2 + 1] > A[n/2] and A[n/2 + 1] > A[n/2 + 2])	dp[n/2 + 1][1][0] = 0, dp[n/2 + 1][1][1] = 1;
		else												dp[n/2 + 1][1][0] = dp[n/2 + 1][1][1] = INT_MAX;

		cntr = n/2;
		wow = 1;
	}

	for(int i = cntr; i >= 1; i--) {
		for(int isUp = 0; isUp <= 1; isUp++) {
			dp[i][isUp][0] = dp[i][isUp][1] = INT_MAX;
      cout<<i<<" "<<isUp<<" "<<(isUp^wow)<<"\n";
			if(satisfy(A[i], A[i + 1], isUp) == 1 and satisfy(A[inv(i + 1)], A[inv(i)], isUp^wow) == 1)		dp[i][isUp][0] = min(dp[i][isUp][0], dp[i + 1][isUp^1][0]);
			if(satisfy(A[i], A[inv(i + 1)], isUp) == 1 and satisfy(A[i + 1], A[inv(i)], isUp^wow) == 1)		dp[i][isUp][0] = min(dp[i][isUp][0], dp[i + 1][isUp^1][1]);

			if(satisfy(A[inv(i)], A[i + 1], isUp) == 1 and satisfy(A[inv(i + 1)], A[i], isUp^wow) == 1 and dp[i + 1][isUp^1][0] != INT_MAX) {
				dp[i][isUp][1] = min(dp[i][isUp][1], dp[i + 1][isUp^1][0] + 1);
			}
			if(satisfy(A[inv(i)], A[inv(i + 1)], isUp) == 1 and satisfy(A[i + 1], A[i], isUp^wow) == 1 and dp[i + 1][isUp^1][1] != INT_MAX) {
				dp[i][isUp][1] = min(dp[i][isUp][1], dp[i + 1][isUp^1][1] + 1);
			}
		}
	}

	int ans = min(min(dp[1][0][0], dp[1][0][1]), min(dp[1][1][0], dp[1][1][1]));

	if(ans == INT_MAX)	ans = -1;

	cout<<ans<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)	solve();
	return 0;
}
