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

  ll n,m;
  cin>>n>>m;

  ll a[n],b[m];
  fr(i,0,n) cin>>a[i];
  fr(i,0,m) cin>>b[i];

  ll ind1=0,ind2=0;

  ll ans=0;
  while(ind1<n && ind2<m){
    if(a[ind1]<=b[ind2]){
      ans++;
      ind1++;
      ind2++;
    }
    else ind1++;
  }

  cout<<ans;

  return 0;
}
