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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool prime[N];

void sieve(){
  MS(prime,true);

  for(ll i=2;i*i<=N;i++){
    if(prime){
      for(ll j=2*i;j<=N;j+=i){
        prime[j]=false;
      }
    }
  }

  prime[0]=prime[1]=false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  sieve();

  ll r;
  fr(i,0,n){
    r=sqrt(a[i]);
    if(r*r==a[i] && prime[r]) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}
