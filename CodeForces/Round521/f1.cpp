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
#define INF 2e15
#define N 205
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k,x;
ll a[N];
ll dp[N][N][N];

ll F(ll i,ll kk,ll xx){
  if(!xx && i>=k) return -INF;
  if(i==0 && xx>0) return -INF;
  if(i>=0 && i<k && !xx) return 0;

  if(dp[i][kk][xx]==-1){
    if(k>1) dp[i][kk][xx]=max(a[i]+F(i-1,k,xx-1),F(i-1,kk-1,xx));
    else dp[i][kk][xx]=a[i]+F(i-1,k,xx-1);
  }

  return dp[i][kk][xx];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k>>x;
  fr(i,1,n+1) cin>>a[i];

  fr(i,0,N) fr(j,0,N) fr(kk,0,N) dp[i][j][kk]=-1;

  

  ll ans=F(n,k,x);

  if(ans<=0) cout<<-1;
  else cout<<ans;

  return 0;
}
