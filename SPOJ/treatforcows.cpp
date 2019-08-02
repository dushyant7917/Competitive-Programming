#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 2001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;
ll a[N];
ll dp[N][N];

ll fn(ll l,ll r){
  ll t=n-(r-l); // time
  if(l==r) return t*a[l];
  else{
    if(dp[l+1][r]==-1) dp[l+1][r]=fn(l+1,r);
    if(dp[l][r-1]==-1) dp[l][r-1]=fn(l,r-1);
    return max(t*a[l]+dp[l+1][r],dp[l][r-1]+t*a[r]);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fr(i,0,N) fr(j,0,N) dp[i][j]=-1;

  cin>>n;
  fr(i,0,n) cin>>a[i];

  cout<<fn(0,n-1);

  return 0;
}
