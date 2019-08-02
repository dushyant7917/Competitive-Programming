#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
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

ll modPow(ll x,ll y,ll m=mod){
  ll res=1;
  x=x%m;

  while(y){
    if(y&1) res=(res*x)%m;
    y/=2;
    x=(x*x)%m;
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll x,k;
  cin>>x>>k;

  if(x==0) cout<<0;
  else if(k==0) cout<<(2*(x%mod))%mod;
  else{
    ll a,b;
    a=(2*x-1)%mod;
    b=modPow(2,k);
    cout<<(a*b+1)%mod;
  }

  return 0;
}
