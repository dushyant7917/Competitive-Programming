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

vector<ll> factors[750007];

void sieve_factors(ll n){
  for(ll i=1;i<n;i++){
    for(ll j=2*i;j<n;j+=i){
      factors[j].PB(i);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  sieve_factors(750007);

  ll n;
  while(t--){
    cin>>n;

    ll a[n];
    fr(i,0,n) cin>>a[i];

    sort(a,a+n);
    ll dp[750007]={0};

    ll ans=0;
    fr(i,0,n){
      dp[a[i]]=1;

      fr(j,0,factors[a[i]].size()){
        dp[a[i]]=((dp[a[i]]%mod)+(dp[factors[a[i]][j]]%mod))%mod;
      }
      ans=((ans%mod)+(dp[a[i]]%mod))%mod;
    }

    cout<<ans<<"\n";
  }

  return 0;
}
