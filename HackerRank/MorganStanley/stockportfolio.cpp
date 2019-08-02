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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll s[n+1],l[n+1],r[n+1];
  fr(i,1,n+1) cin>>s[i];
  fr(i,1,n+1) cin>>l[i];
  fr(i,1,n+1) cin>>r[i];

  ll dp[n+1]={0};

  ll mv=0;
  fr(i,1,n+1){
    dp[i]=dp[i-1];
    for(ll j=1;j<i-l[i];j++){
      if(j+r[j]<i){
        dp[i]=max(dp[i],dp[j]+s[i]);
      }
    }
    mv=max(mv,dp[i]);
  }

  cout<<mv;

  return 0;
}
