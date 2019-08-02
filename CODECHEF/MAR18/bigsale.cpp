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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  dbl ans;
  while(t--){
    cin>>n;
    ll p[n],q[n],d[n];
    dbl c[n],np[n];
    fr(i,0,n) cin>>p[i]>>q[i]>>d[i];

    fr(i,0,n){
      c[i]=(dbl)(((d[i]*p[i])+(p[i]*100))*d[i])/10000.0;
      np[i]=(dbl)((d[i]*p[i])+(p[i]*100))/100.0;
    }

    ans=0.0;
    fr(i,0,n){
      ans+=((dbl)p[i]-(np[i]-c[i]))*(dbl)q[i];
    }

    cout<<fixed<<setprecision(9)<<ans<<"\n";
  }

  return 0;
}
