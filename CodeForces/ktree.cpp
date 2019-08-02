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

ll n,k,d;
ll dp[102][2];

// w : weight
// f : flag for if edge with weight >=d has occured or not

ll dfs(ll w,ll f){
  if(w>n) return 0;
  if(w==n) return (f)?1:0;

  if(dp[w][f]!=-1) return dp[w][f];

  ll cnt=0;
  fr(i,1,k+1){
    if(i>=d) cnt=(cnt+dfs(w+i,1))%mod;
    else cnt=(cnt+dfs(w+i,f))%mod;
  }

  dp[w][f]=cnt;
  return dp[w][f];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k>>d;

  fr(i,0,102) fr(j,0,2) dp[i][j]=-1;
  cout<<dfs(0,0);

  return 0;
}
