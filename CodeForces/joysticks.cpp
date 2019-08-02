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

ll a,b;
ll dp[101][101];

ll fn(ll a,ll b){
  if(a<=0 || b<=0) return 0;
  if(a==1 && b==1) return 0;
  else{
    if(dp[a][b]==-1) dp[a][b]=1+max(fn((a<100)?a+1:a,b-2),fn(a-2,(b<100)?b+1:b));
    return dp[a][b];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fr(i,0,101) fr(j,0,101) dp[i][j]=-1;

  cin>>a>>b;
  cout<<fn(a,b);

  return 0;
}
