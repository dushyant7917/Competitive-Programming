#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c,d) min(a,min(b,min(c,d)))
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll a[N];
ll dp[N][2][2];

ll inv(ll i){
  return (n-i+1);
}

bool check(ll i,ll j,ll m){
  if(m==0) return a[i]<a[j];
  else return a[i]>a[j];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll ans,start,m;
  while(t--){
    MS(dp,0);

    cin>>n;
    fr(i,1,n+1) cin>>a[i];

    if(n==1) cout<<0<<"\n";

    else{
      if(n%2==0){
        fr(j,0,2){
          if(check(n/2,n/2+1,j)) dp[n/2][j][0]=0;
          else dp[n/2][j][0]=INF;

          if(check(inv(n/2),inv(n/2+1),j)) dp[n/2][j][1]=1;
          else dp[n/2][j][1]=INF;
        }

        start=n/2-1;
        m=0;
      }
      else{
        if(a[n/2+1]<a[n/2] && a[n/2+1]<a[n/2+2]) dp[n/2+1][0][0]=0,dp[n/2+1][0][1]=1;
        else dp[n/2+1][0][0]=dp[n/2+1][0][1]=INF;

        if(a[n/2+1]>a[n/2] && a[n/2+1]>a[n/2+2]) dp[n/2+1][1][0]=0,dp[n/2+1][1][1]=1;
        else dp[n/2+1][1][0]=dp[n/2+1][1][1]=INF;

        start=n/2;
        m=1;
      }

      rf(i,start,0){
        fr(j,0,2){
          dp[i][j][0]=dp[i][j][1]=INF;
          if(check(i,i+1,j) && check(inv(i+1),inv(i),j^m)) dp[i][j][0]=min(dp[i][j][0],dp[i+1][j^1][0]);
          if(check(i,inv(i+1),j) && check(i+1,inv(i),j^m)) dp[i][j][0]=min(dp[i][j][0],dp[i+1][j^1][1]);
          if(check(inv(i),i+1,j) && check(inv(i+1),i,j^m) && dp[i+1][j^1][0]!=INF) dp[i][j][1]=min(dp[i][j][1],1+dp[i+1][j^1][0]);
          if(check(inv(i),inv(i+1),j) && check(i+1,i,j^m) && dp[i+1][j^1][1]!=INF) dp[i][j][1]=min(dp[i][j][1],1+dp[i+1][j^1][1]);
        }
      }

      ans=MIN(dp[1][0][0],dp[1][1][1],dp[1][0][1],dp[1][1][0]);
      if(ans==INF) cout<<-1<<"\n";
      else cout<<ans<<"\n";
    }
  }

  return 0;
}
