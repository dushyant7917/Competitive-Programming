#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n,m;
  while(t--){
    cin>>n>>m;
    ll price[n][m],discount[n][m],dp[n][m];

    fr(i,0,n) fr(j,0,m) cin>>price[i][j];
    fr(i,0,n) fr(j,0,m) cin>>discount[i][j];

    ll cur_min=LLONG_MAX;
    fr(j,0,m){
      dp[0][j]=price[0][j];
      cur_min=min(cur_min,dp[0][j]);
    }

    fr(i,1,n){
      fr(j,0,m){
        dp[i][j]=min(cur_min+price[i][j],dp[i-1][j]+max(0LL,price[i][j]-discount[i-1][j]));
      }

      cur_min=LLONG_MAX;
      fr(j,0,m) cur_min=min(cur_min,dp[i][j]);
    }

    cout<<cur_min<<"\n";
  }

  return 0;
}
