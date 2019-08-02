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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char dp[N];

  ll k,l,n;
  cin>>k>>l>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  dp[0]='B';
  dp[1]='A';
  fr(i,2,N){
    if(dp[i-1]=='B') dp[i]='A';
    else if(i-k>=0 && dp[i-k]=='B') dp[i]='A';
    else if(i-l>=0 && dp[i-l]=='B') dp[i]='A';
    else dp[i]='B';
  }

  fr(i,0,n){
    cout<<dp[a[i]];
  }

  return 0;
}
