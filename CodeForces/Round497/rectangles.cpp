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

  pii p[n];
  fr(i,0,n) cin>>p[i].fi>>p[i].se;

  if(p[0].se<p[0].fi) swap(p[0].fi,p[0].se);

  fr(i,1,n){
    if(p[i].se>p[i-1].se && p[i].fi<=p[i-1].se) swap(p[i].fi,p[i].se);
    if(p[i].fi<=p[i-1].se && p[i].fi>p[i].se) swap(p[i].fi,p[i].se);
    if(p[i].fi>p[i-1].se && p[i].se>p[i-1].se){
      cout<<"NO";
      return 0;
    }
  }

  cout<<"YES";

  return 0;
}
