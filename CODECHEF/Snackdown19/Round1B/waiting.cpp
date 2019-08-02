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

  ll t;
  cin>>t;

  ll n,m,k,l;
  while(t--){
    cin>>n>>m>>k>>l;
    ll a[n+1];
    fr(i,0,n) cin>>a[i];

    a[n]=k;
    n++;

    sort(a,a+n);

    ll tm=(m*l)+l;
    ll ans=INF;

    fr(i,0,n){
      if(a[i]>k) break;
      
      if(a[i]>=tm){
        ans=0;
        break;
      }
      else{
        ans=min(ans,tm-a[i]);
        tm+=l;
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
