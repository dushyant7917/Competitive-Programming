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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k,x;
  cin>>n>>k>>x;

  ll dp[n+1];
  dp[0]=0;
  dp[1]=1;
  fr(i,2,n+1){
    dp[i]=((k-1)*dp[i-2])+((k-2)*dp[i-1]);
  }

  if(x==1) cout<<dp[n-1]%mod;
  else cout<<(dp[n]/(k-1))%mod;

  return 0;
}
