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
#define INF 2e10
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

  ll n,m,ans;
  while(t--){
    cin>>n>>m;
    ll a[n][m],up[n][m],down[n][m],left[n][m],right[n][m];
    fr(i,0,n) fr(j,0,m) cin>>a[i][j];

    fr(i,0,n){
      left[i][0]=a[i][0];
      fr(j,1,m) left[i][j]=max(left[i][j-1]+a[i][j],a[i][j]);
      right[i][m-1]=a[i][m-1];
      rf(j,m-2,0) right[i][j]=max(right[i][j+1]+a[i][j],a[i][j]);
    }

    fr(j,0,m){
      up[0][j]=a[0][j];
      fr(i,1,n) up[i][j]=max(up[i-1][j]+a[i][j],a[i][j]);
      down[n-1][j]=a[n-1][j];
      rf(i,n-2,0) down[i][j]=max(down[i+1][j]+a[i][j],a[i][j]);
    }

    ans=-INF;

    fr(i,1,n-1){
      fr(j,1,m-1){
        ans=max(ans,a[i][j]+left[i][j-1]+right[i][j+1]+up[i-1][j]+down[i+1][j]);
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
