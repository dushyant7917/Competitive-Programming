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

  ll t;
  cin>>t;

  ll W,n;
  while(t--){
    cin>>W>>n;

    ll v[n+1],c[n+1],l[n+1],linked[n+1][2],dp[n+1][W+1];

    fr(i,1,n+1) linked[i][0]=linked[i][1]=0;
    fr(i,0,n+1) fr(j,0,W+1) dp[i][j]=0;

    fr(i,1,n+1){
      cin>>v[i]>>c[i]>>l[i];

      if(linked[l[i]][0]) linked[l[i]][1]=i;
      else linked[l[i]][0]=i;
    }

    ll x,y;

    fr(i,1,n+1){
      fr(j,1,W+1){
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(l[i]) continue;
        if(v[i]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+v[i]*c[i]);
        x=linked[i][0];
        y=linked[i][1];
        if(!x) continue;
        if(v[i]+v[x]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-(v[i]+v[x])]+v[i]*c[i]+v[x]*c[x]);
        if(!y) continue;
        if(v[i]+v[y]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-(v[i]+v[y])]+v[i]*c[i]+v[y]*c[y]);
        if(v[i]+v[x]+v[y]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-(v[i]+v[x]+v[y])]+v[i]*c[i]+v[x]*c[x]+v[y]*c[y]);
      }
    }

    cout<<dp[n][W]<<"\n";
  }

  return 0;
}
