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
#define INF 1e15-1
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()

string rev(string s){
  reverse(s.begin(),s.end());
  return s;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll c[n];
  string s[n],r[n];
  fr(i,0,n) cin>>c[i];
  fr(i,0,n){
    cin>>s[i];
    r[i]=rev(s[i]);
  }

  ll dp[n][2];
  fr(i,0,n) dp[i][0]=dp[i][1]=INF;
  dp[0][0]=0;
  dp[0][1]=c[0];

  fr(i,1,n){
    dp[i][0]=dp[i][1]=INF;
    if(s[i]>=s[i-1]) dp[i][0]=min(dp[i][0],dp[i-1][0]);
    if(s[i]>=r[i-1]) dp[i][0]=min(dp[i][0],dp[i-1][1]);
    if(r[i]>=s[i-1]) dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
    if(r[i]>=r[i-1]) dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
  }

  ll ans=min(dp[n-1][0],dp[n-1][1]);
  cout<<((ans==INF)?-1:ans);

  return 0;
}
