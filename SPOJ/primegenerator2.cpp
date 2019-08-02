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
#define N 5e5+5
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

vector<ll> prime;

void sieve(ll n){
  bool mark[n+1];
  MS(mark,true);

  for(ll i=2;i*i<=n;i++){
    if(mark[i]){
      for(ll j=2*i;j<=n;j+=i){
        mark[j]=false;
      }
    }
  }

  fr(i,2,n+1){
    if(mark[i]) prime.PB(i);
  }
}

void prime_range(ll m,ll n){
  ll limit=N;

  if(n<=N){
    fr(i,0,SZ(prime)){
      if(prime[i]>=m && prime[i]<=n) cout<<prime[i]<<"\n";
      if(prime[i]>n) break;
    }
    return;
  }

  ll low=m,high=m*2;
  if(high>n) high=n;
  while(low<=n){
    bool mark[limit+1];
    MS(mark,true);

    ll start;
    fr(i,0,SZ(prime)){
      start=(low/prime[i])*prime[i];
      if(start<low) start+=prime[i];

      for(ll j=start;j<=high;j+=prime[i]) mark[j-low]=false;
    }

    fr(i,low,high+1){
      if(mark[i-low]) cout<<i<<"\n";
    }

    low+=limit;
    high+=limit;
    if(high>n) high=n;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  sieve(N);

  ll t;
  cin>>t;

  ll m,n;
  while(t--){
    cin>>m>>n;
    prime_range(m,n);
    cout<<"\n";
  }

  return 0;
}
