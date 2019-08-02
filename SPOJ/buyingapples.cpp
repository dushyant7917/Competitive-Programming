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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll price[N];
ll dp[N][N];

ll F(ll i,ll k){
  if(i<0 || k<0) return INF;
  if(i==0 && k>0) return INF;
  if(k==0) return 0;

  if(dp[i][k]==-1){
    if(price[i]!=-1) dp[i][k]=min(price[i]+F(i,k-i),F(i-1,k));
    else dp[i][k]=F(i-1,k);
  }

  return dp[i][k];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,k,ans;
  while(t--){
    cin>>n>>k;
    fr(i,1,k+1) cin>>price[i];
    fr(i,0,N) fr(j,0,N) dp[i][j]=-1;
    ans=F(k,k);
    if(ans==INF) cout<<-1<<"\n";
    else cout<<ans<<"\n";
  }

  return 0;
}
