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
#define N 2001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()

vector<ll> divisors[N];
ll dp[N][N];

ll F(ll n,ll k){
  if(k==1) return 1;
  if(dp[n][k]==-1){
    ll s=0;
    fr(i,0,divisors[n].size()){
      s=(s+F(divisors[n][i],k-1))%mod;
    }
    dp[n][k]=s;
  }
  return dp[n][k];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  fr(i,1,N){
    for(ll j=i;j<N;j+=i){
      divisors[j].PB(i);
    }
  }

  fr(i,0,N) fr(j,0,N) dp[i][j]=-1;

  ll ans=0;
  fr(i,1,n+1){
    ans=(ans+F(i,k))%mod;
  }
  cout<<ans;

  return 0;
}
