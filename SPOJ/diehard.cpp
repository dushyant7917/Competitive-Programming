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
#define N 2001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll dp[N][N];

ll fn(ll h,ll a){
  if(h<=0 || a<=0) return 0;
  else{
    if(dp[h][a]==-1) dp[h][a]=max(2+fn(h-2,a-8),2+fn(h-17,a+7));
    return dp[h][a];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;


  ll H,A;
  while(t--){
    cin>>H>>A;

    fr(i,0,N){
      fr(j,0,N){
        dp[i][j]=-1;
      }
    }

    cout<<fn(H,A)-1<<"\n";
  }

  return 0;
}
