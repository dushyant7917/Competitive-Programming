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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll max_prime_factor(ll n){
  ll mpf=1ll;

  while(n && n%2==0){
    mpf=max(2ll,mpf);
    n/=2ll;
  }

  for(ll pf=3;pf*pf<=n;pf+=2){
    while(n && n%pf==0){
      mpf=max(mpf,pf);
      n/=pf;
    }
  }

  if(n>2) mpf=max(mpf,n);

  return mpf;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,k;
  while(t--){
    cin>>n>>k;

    ll a[n];
    fr(i,0,n) cin>>a[i];

    ll x;
    x=a[0];
    fr(i,1,n) x=__gcd(x,a[i]);

    if(max_prime_factor(x)<=k) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}
