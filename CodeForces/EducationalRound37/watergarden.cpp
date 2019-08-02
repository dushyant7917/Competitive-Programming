#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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
  ll t;
  cin>>t;

  ll n,k;
  while(t--){
    cin>>n>>k;
    ll x[k+1];
    ll t[n+1]={0};
    fr(i,1,k+1) cin>>x[i],t[x[i]]=1;

    ll ans=0,l,r;
    fr(i,1,k+1){
      //cout<<x[i]<<" ";
      l=0;
      fr(j,1,n+1){
        if(j==x[i]) break;
        if(t[j]) l=j;
      }
      r=n+1;
      rf(j,n,0){
        if(j==x[i]) break;
        if(t[j]) r=j;
      }
      //cout<<l<<" "<<r<<" ";
      if(l==0) ans=max(ans,x[i]-l);
      else ans=max(ans,(x[i]-l)/2+1);
      if(r==n+1) ans=max(ans,r-x[i]);
      else ans=max(ans,(r-x[i])/2+1);
      //cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
  }

  return 0;
}
