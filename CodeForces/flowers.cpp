#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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

ll dp[N];
ll sum[N];
ll k;

ll cal(){
  fr(i,0,k){
    dp[i]=1;
    sum[i]=i+1;
  }

  fr(i,k,N){
    dp[i]=((dp[i-1]%mod)+(dp[i-k]%mod))%mod;
    sum[i]=((sum[i-1]%mod)+(dp[i]%mod))%mod;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t>>k;

  cal();

  ll a,b;
  while(t--){
    cin>>a>>b;
    cout<<((sum[b]-sum[a-1]<0)?(sum[b]-sum[a-1]+mod):(sum[b]-sum[a-1]))<<"\n";
  }

  return 0;
}
