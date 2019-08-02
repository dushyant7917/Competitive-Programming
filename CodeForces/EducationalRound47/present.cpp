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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  dbl val=0.0;
  dbl x[m],d[m];

  fr(i,0,m) cin>>x[i]>>d[i];

  dbl sz=(dbl)n,h=(dbl)(n/2);

  fr(i,0,m){
    val+=sz*x[i];

    if(d[i]<0){
      if(n&1) val+=d[i]*h*(h+1);
      else val+=(d[i]*h*(h+1))-(d[i]*h);
    }
    else val+=d[i]*sz*(sz-1.0)*0.5;
  }

  cout<<fixed<<setprecision(6)<<(dbl)(val/(dbl)n);

  return 0;
}
