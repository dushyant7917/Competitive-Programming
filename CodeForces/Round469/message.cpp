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

  ll n,m;
  cin>>n>>m;
  ll a[n+1],b[m+1],pa[n+1]={0},pb[m+1]={0};
  fr(i,1,n+1) cin>>a[i];
  fr(i,1,m+1) cin>>b[i];

  fr(i,1,n+1) pa[i]=pa[i-1]+a[i];
  fr(i,1,m+1) pb[i]=pb[i-1]+b[i];

  ll ans=0,as,bs;
  ll i,j,pi,pj;
  pi=pj=0;
  i=j=1;
  while(i<=n && j<=m){
    as=pa[i]-pa[pi];
    bs=pb[j]-pb[pj];

    if(as>bs) j++;
    else if(as<bs) i++;
    else{
      ans++;
      pi=i;
      pj=j;
      i++;
      j++;
    }

    if(i==n+1 && j<=m) i=n;
    if(j==m+1 && i<=n) j=m;
  }

  cout<<ans;

  return 0;
}
