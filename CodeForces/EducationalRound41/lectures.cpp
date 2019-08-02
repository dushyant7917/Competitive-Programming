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

  ll n,k;
  cin>>n>>k;
  ll a[n+1],t[n+1];
  fr(i,1,n+1) cin>>a[i];
  fr(i,1,n+1) cin>>t[i];

  ll ps[n+1]={0};
  ll sum=0;
  fr(i,1,n+1){
    if(t[i]){
      ps[i]=ps[i-1];
      sum+=a[i];
    }
    else ps[i]=ps[i-1]+a[i];
  }

  ll extra=0;
  fr(i,k,n+1) extra=max(extra,ps[i]-ps[i-k]);

  cout<<sum+extra;

  return 0;
}
