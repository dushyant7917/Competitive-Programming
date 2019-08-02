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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,m;
ll a[N][N];
ll dp[N][N];

ll fn(ll r,ll c){
  if(r<0 || r>=n || c<0 || c>=m) return INF;
  if(r==n-1) return a[r][c];
  else{
    if(dp[r][c]==-1) dp[r][c]=a[r][c]+MIN(fn(r+1,c),fn(r+1,c-1),fn(r+1,c+1));
    return dp[r][c];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fr(i,0,N) fr(j,0,N) dp[i][j]=-1;

  cin>>n>>m;
  fr(i,0,n) fr(j,0,m) cin>>a[i][j];

  ll mf=INF;
  fr(j,0,m){
    mf=min(mf,fn(0,j));
  }

  cout<<mf;

  return 0;
}
