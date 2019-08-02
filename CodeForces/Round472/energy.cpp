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
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,u;
ll a[N];

ll BS(ll i,ll l,ll r){
  ll ind=-1,m;

  while(l<=r){
    m=(l+r)/2;
    if(a[m]-a[i]<=u){
      ind=m;
      l=m+1;
    }
    else r=m-1;
  }

  return ind;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>u;
  fr(i,0,n) cin>>a[i];

  ll ind;
  dbl ans=0.0;

  fr(i,0,n-2){
    ind=BS(i,i+2,n-1);
    if(ind!=-1){
      ans=MAX(ans,(dbl)(a[ind]-a[i+1])/(dbl)(a[ind]-a[i]));
    }
  }

  if(ans==0.0) cout<<-1;
  else cout<<fixed<<setprecision(10)<<ans;

  return 0;
}
