#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;
  ll a[n][m],dp[n][m];

  fr(i,0,n) fr(j,0,m) cin>>a[i][j];

  fr(j,0,m) dp[0][j]=a[0][j];

  fr(i,1,n){
    fr(j,0,m){
      if(j==0) dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
      else if(j==m-1) dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
      else dp[i][j]=a[i][j]+MIN(dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]);
    }
  }

  ll mf=INF;
  fr(j,0,m){
    mf=min(mf,dp[n-1][j]);
  }

  cout<<mf;

  return 0;
}
