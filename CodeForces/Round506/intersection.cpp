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
#define N 22
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

  pii a[n];
  multiset<ll> ml,mr;

  fr(i,0,n){
    cin>>a[i].fi>>a[i].se;
    ml.insert(a[i].fi);
    mr.insert(a[i].se);
  }

  ll ans=0;

  fr(i,0,n){
    ml.erase(ml.find(a[i].fi));
    mr.erase(mr.find(a[i].se));
    ans=max(ans,(*mr.begin()) - (*ml.rbegin()));
    ml.insert(a[i].fi);
    mr.insert(a[i].se);
  }

  cout<<ans;

  return 0;
}
