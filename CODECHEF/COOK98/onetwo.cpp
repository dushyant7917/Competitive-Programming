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
#define N 2000001
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

  ll n,mx;

  while(t--){
    cin>>n;

    ll a[n+1],ps[n+1]={0};

    fr(i,1,n+1) cin>>a[i];

    fr(i,1,n+1) ps[i]=a[i]+ps[i-1];

    mx=0;

    fr(i,1,n+1){
      if(a[i]==1){
        mx=MAX(mx,ps[i],ps[n]-ps[i-1]);
      }
    }

    cout<<mx+((ps[n]-mx)/2)<<"\n";
  }

  return 0;
}
