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
  ll t;
  cin>>t;

  ll n,cnt=1,ans=0;
  while(t--){
    cin>>n;
    ll a[n],dp[n];
    fr(i,0,n) cin>>a[i];

    if(n){
      dp[0]=a[0];
      fr(i,1,n){
        if(i>=2) dp[i]=max(dp[i-1],a[i]+dp[i-2]);
        else dp[i]=max(dp[i-1],a[i]);
      }
      ans=dp[n-1];
    }

    cout<<"Case "<<cnt++<<": "<<ans<<"\n";
  }

  return 0;
}
