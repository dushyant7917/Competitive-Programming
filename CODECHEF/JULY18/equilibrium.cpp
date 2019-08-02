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

ll power(ll x,ll y){
  ll res=1;
  x=x%mod;

  while(y>0){
    if(y&1) res=((res%mod)*(x%mod))%mod;
    y=y>>1;
    x=((x%mod)*(x%mod))%mod;
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;

  ll num,den;
  num=power(2,n-1)-n;
  den=power(2,n-1);

  cout<<((power(den,mod-2)%mod)*(num%mod))%mod;

  return 0;
}
