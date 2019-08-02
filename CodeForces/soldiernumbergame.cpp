#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 5000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll spf[N],npf[N],dp[N];

void smallestPrimeFactors(){
  fr(i,1,N) spf[i]=i;

  for(ll i=2;i<N;i+=2) spf[i]=2;

  for(ll i=3;i*i<=N;i++){
    if(spf[i]==i){
      for(ll j=i*i;j<N;j+=i){
        if(spf[j]==j) spf[j]=i;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  smallestPrimeFactors();
  npf[1]=0;
  fr(i,2,N) npf[i]=npf[i/spf[i]]+1;
  dp[0]=0;
  fr(i,1,N) dp[i]=dp[i-1]+npf[i];

  ll a,b;
  while(t--){
    cin>>a>>b;
    cout<<dp[a]-dp[b]<<"\n";
  }

  return 0;
}
