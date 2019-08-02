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
#define N 1002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,l;
  cin>>n>>l;

  dbl a[n];
  fr(i,0,n) cin>>a[i];

  sort(a,a+n);

  dbl ans=0.0;

  if(n==1){
    cout<<fixed<<setprecision(10)<<max(a[0]-0,l-a[0]);
    return 0;
  }

  fr(i,0,n){
    if(i==0) ans=MAX(ans,a[i]-0,(a[i+1]-a[i])*0.5);
    else if(i==n-1) ans=MAX(ans,l-a[i],(a[i]-a[i-1])*0.5);
    else ans=MAX(ans,(a[i]-a[i-1])*0.5,(a[i+1]-a[i])*0.5);
  }

  cout<<fixed<<setprecision(10)<<ans;

  return 0;
}
