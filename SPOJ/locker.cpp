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
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

map<ll,ll> dp;

ll F(ll b){
  ll a=3,ans=1;
  a=a%mod;

  while(b){
    if(b&1) ans=(ans*a)%mod;
    a=(a*a)%mod;
    b=b/2;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,ans;
  while(t--){
    cin>>n;

    if(n==1){
      cout<<1<<"\n";
      continue;
    }

    ans=1;
    if(n%3==1) ans=(ans*4*F((n-4)/3))%mod;
    else if(n%3==2) ans=(ans*2*F(n/3))%mod;
    else ans=(ans*F(n/3))%mod;
    cout<<ans<<"\n";
  }

  return 0;
}
