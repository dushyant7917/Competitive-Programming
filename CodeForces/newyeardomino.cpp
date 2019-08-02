#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
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

  ll n,m,r1,c1,r2,c2,q,ans;

  cin>>n>>m;

  char a[n+1][m+1];
  ll dp[n+1][m+1],h[n+1][m+1],v[n+1][m+1];
  MS(dp,0);
  MS(h,0);
  MS(v,0);

  fr(i,1,n+1) fr(j,1,m+1) cin>>a[i][j];

  fr(i,1,n+1) fr(j,1,m+1){
    if(a[i][j]=='.' && j+1<=m && a[i][j+1]=='.') dp[i][j]++,h[i][j]=1;
    if(a[i][j]=='.' && i+1<=n && a[i+1][j]=='.') dp[i][j]++,v[i][j]=1;
  }
  fr(i,1,n+1) fr(j,1,m+1) dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

  cin>>q;
  fr(k,0,q){
    cin>>r1>>c1>>r2>>c2;
    ans=dp[r2][c2]-dp[r2][c1-1]-dp[r1-1][c2]+dp[r1-1][c1-1];
    fr(r,r1,r2+1) if(h[r][c2]) ans--;
    fr(c,c1,c2+1) if(v[r2][c]) ans--;
    cout<<ans<<"\n";
  }

  return 0;
}
