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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  ll c=1;
  while(cin>>n && n!=0){
    ll a[n][3],dp[n][3];
    fr(i,0,n){
      fr(j,0,3){
        cin>>a[i][j];
      }
    }

    fr(i,0,n){
      if(i==0){
        dp[i][0]=INF;
        dp[i][1]=a[i][1];
        dp[i][2]=a[i][2]+dp[i][1];
      }
      else if(i==1){
        dp[i][0]=a[i][0]+dp[i-1][1];
        dp[i][1]=a[i][1]+MIN(dp[i-1][1],dp[i-1][2],dp[i][0]);
        dp[i][2]=a[i][2]+MIN(dp[i][1],dp[i-1][1],dp[i-1][2]);
      }
      else{
        dp[i][0]=a[i][0]+min(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=a[i][1]+MIN(min(dp[i][0],dp[i-1][0]),dp[i-1][1],dp[i-1][2]);
        dp[i][2]=a[i][2]+MIN(dp[i][1],dp[i-1][1],dp[i-1][2]);
      }
    }

    cout<<c++<<". "<<dp[n-1][1]<<"\n";
  }

  return 0;
}
