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
#define N 1001
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
  ll a[k+1][n+1],pos[k+1][1001],dp[n+1];

  fr(i,1,k+1){
    fr(j,1,n+1){
      cin>>a[i][j];
      pos[i][a[i][j]]=j;
    }
  }

  bool flag;
  fr(i,1,n+1){
    dp[i]=1;
    fr(j,1,i){
      flag=true;
      fr(p,1,k+1){
        if(pos[p][a[1][j]]>=pos[p][a[1][i]]) flag=false;
      }
      if(flag) dp[i]=max(dp[i],dp[j]+1);
    }
  }

  ll ans=1;
  fr(i,1,n+1) ans=max(ans,dp[i]);
  cout<<ans;

  return 0;
}
