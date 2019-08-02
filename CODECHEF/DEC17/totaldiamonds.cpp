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

ll diff[2*N];
ll sum[2*N];

ll cal(ll n){
  ll s1=0,s2=0,d;
  while(n>0){
    d=n%10;
    if(d&1) s1+=d;
    else s2+=d;
    n/=10;
  }
  return abs(s1-s2);
}

void init(){
  fr(i,0,2*N) diff[i]=cal(i);
  fr(i,0,2*N) sum[i]=sum[i-1]+diff[i];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  init();

  ll dp[N];

  ll x,y;
  dp[1]=2;

  fr(i,2,N){
    dp[i]=dp[i-1]+2*(sum[2*i-1]-sum[i])+diff[2*i];
  }

  ll n;
  while(t--){
    cin>>n;
    cout<<dp[n]<<"\n";
  }

  return 0;
}
