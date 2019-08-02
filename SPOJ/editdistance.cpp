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

ll MIN(ll a,ll b,ll c){
  return min(min(a,b),c);
}

ll ans(string s1,string s2,ll n1,ll n2){
  ll dp[n1+1][n2+1];

  fr(i,0,n1+1){
    fr(j,0,n2+1){
      if(!i && !j) dp[i][j]=0;
      else if(!i) dp[i][j]=j;
      else if(!j) dp[i][j]=i;
      else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
      else dp[i][j]=1+MIN(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
    }
  }

  return dp[n1][n2];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string s1,s2;
  while(t--){
    cin>>s1>>s2;
    cout<<ans(s1,s2,s1.size(),s2.size())<<"\n";
  }

  return 0;
}
