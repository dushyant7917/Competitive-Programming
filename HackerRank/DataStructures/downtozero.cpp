#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll dp[N];

void cal(){
  memset(dp,-1,sizeof(dp));
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  dp[3]=3;

  fr(i,0,N){
    if(dp[i]==-1 || dp[i]>dp[i-1]+1) dp[i]=dp[i-1]+1;
    for(ll j=1;j<=i && j*i<N;j++){
      if(dp[j*i]==-1 || dp[i]+1<dp[j*i]) dp[j*i]=dp[i]+1;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  cal();

  ll n;
  while(t--){
    cin>>n;
    cout<<dp[n]<<"\n";
  }

  return 0;
}
