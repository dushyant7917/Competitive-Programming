#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll n,a,b,c;
map<ll,ll> dp;

/*
ll fn(ll n){
  if(n<0)
    return gmin; // gmin=-infinity
  else if(n==0)
    return 0;
  else{
    if(dp[n]) return dp[n];
    else{
      dp[n]=max(1+fn(n-a),max(1+fn(n-b),1+fn(n-c)));
      return dp[n];
    }
  }
}
*/
ll DP(ll x){
  if(x<0)
    return gmin;
  else if(x==0)
    return 0;
  else
    return dp[x];
}

ll fn(ll n){
  fr(i,0,n+1){
    dp[i]=max(1+dp(n-a),max(1+fn(n-b),1+fn(n-c)));
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>a>>b>>c;

  cout<<fn(n);

  return 0;
}
