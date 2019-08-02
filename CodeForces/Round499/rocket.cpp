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
#define N 1001
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

  dbl a[n],b[n];
  fr(i,0,n) cin>>a[i];
  fr(i,0,n) cin>>b[i];

  fr(i,0,n){
    if(a[i]==1){
      cout<<-1;
      return 0;
    }
  }

  fr(i,0,n){
    if(b[i]==1){
      cout<<-1;
      return 0;
    }
  }

  dbl ans=m;
  ll t=0,l=1;

  fr(i,0,n){
    ans+=ans/(a[t]-1.0);
    ans+=ans/(b[l]-1.0);
    t++;
    l++;
    if(l==n) l=0;
  }

  cout<<fixed<<setprecision(6)<<ans-m;

  return 0;
}
