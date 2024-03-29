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

  ll w,l;
  cin>>w>>l;

  ll a[w];
  fr(i,1,w) cin>>a[i];

  ll sum[w]={0},ans=INF;
  fr(i,1,w){
    sum[i]=a[i]+sum[i-1];
    if(i>=l) ans=min(ans,sum[i]-sum[i-l]);
  }

  cout<<ans;

  return 0;
}
