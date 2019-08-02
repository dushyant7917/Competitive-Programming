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

map<ll,ll> dp;

ll mp(ll n){
  if(n==0) return 0;

  if(dp[n]!=0) return dp[n];
  else{
    dp[n]=max(n,mp(n/2)+mp(n/3)+mp(n/4));
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  while(cin>>n){
    cout<<mp(n)<<"\n";
  }

  return 0;
}
