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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,b;
  cin>>n>>b;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll l=1,r=0,m,cakes,ans=-1;

  fr(i,0,n) r=max(r,a[i]);

  while(l<=r){
    m=(l+r)/2;
    cakes=0;
    fr(i,0,n) cakes+=ceil((a[i]/(float)m));
    if(cakes<=b){
      ans=m;
      r=m-1;
    }
    else l=m+1;
  }

  cout<<ans;

  return 0;
}
