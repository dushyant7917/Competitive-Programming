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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;
ll dp[N][N];
ll arr[N];

ll sum(ll a,ll b){
  ll s=0;
  fr(i,a,b+1) s+=arr[i];
  return s%100;
}

ll fn(ll a,ll b){
  if(a==b) return 0;

  ll ans=INF,smoke;
  fr(i,a,b){
    if(dp[a][i]==-1) dp[a][i]=fn(a,i);
    if(dp[i+1][b]==-1) dp[i+1][b]=fn(i+1,b);
    smoke=sum(a,i)*sum(i+1,b)+dp[a][i]+dp[i+1][b];
    ans=min(ans,smoke);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(cin>>n){
    fr(i,0,n) cin>>arr[i];
    fr(i,0,n) fr(j,0,n) dp[i][j]=-1;
    cout<<fn(0,n-1)<<"\n";
  }

  return 0;
}
