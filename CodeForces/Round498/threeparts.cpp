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

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  map<ll,ll> pm,sm,mp;
  ll ps[n],ss[n];
  ps[0]=a[0];
  ss[n-1]=a[n-1];
  pm[ps[0]]=0;
  sm[ss[n-1]]=n-1;
  mp[ss[n-1]]=1;

  fr(i,1,n){
    ps[i]=ps[i-1]+a[i];
    pm[ps[i]]=i;
  }
  rf(i,n-2,0){
    ss[i]=ss[i+1]+a[i];
    sm[ss[i]]=i;
    mp[ss[i]]=1;
  }

  ll ans=0;
  fr(i,0,n){
    if(mp[ps[i]] && sm[ps[i]]>pm[ps[i]]){
      ans=max(ans,ps[i]);
    }
  }

  cout<<ans;

  return 0;
}
