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
#define N 5001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,k;
ll a[N];
ll sum[N];
ll dp[N][N];

ll fn(ll i,ll s){
  if(i>n || s>=k) return 0;
  if(i+m-1>n) return dp[i][s]=0;
  if(s>k) return dp[i][s]=0;
  
  if(dp[i][s]==-1) dp[i][s]=max((sum[i+m-1]-sum[i-1])+fn(i+m,s+1),fn(i+1,s));
  return dp[i][s];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  MS(a,0);
  MS(sum,0);
  MS(dp,-1);

  cin>>n>>m>>k;
  fr(i,1,n+1) cin>>a[i];

  fr(i,1,n+1) sum[i]=sum[i-1]+a[i];

  cout<<fn(1,0);

  return 0;
}
