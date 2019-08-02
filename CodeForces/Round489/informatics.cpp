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

  ll l,r,x,y,p;
  cin>>l>>r>>x>>y;
  p=x*y;

  ll ans=0;
  map<ll,ll> mp;

  ll start;
  if(x>=l) start=x;
  else if(l%x==0) start=l;
  else start=((l/x)+1)*x;

  for(ll i=start;i*i<=r,i*i<=p;i+=x){
    if((p/i)<l || (p/i)>r) continue;
    if(mp[i] || mp[p/i]) continue;
    if(p%i!=0) continue;
    if(i%x!=0) continue;
    if(__gcd(i,p/i)==x){
      ans++;
      if(i!=p/i) ans++;
      mp[i]=1;
      mp[p/i]=1;
    }
  }

  cout<<ans;

  return 0;
}
