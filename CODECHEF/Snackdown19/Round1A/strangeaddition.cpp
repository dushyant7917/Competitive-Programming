#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 32
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll A,B,C;
ll dp[N][N][N][2];

ll calSum(ll x,ll y,ll z){
  return (x+y+z)%2;
}

ll calCarry(ll x,ll y,ll z){
  return (x+y+z)/2;
}

ll F(ll i,ll bitsA,ll bitsB,ll carry){
  if(bitsA<0 || bitsB<0) return 0;
  if(i==N && !bitsA && !bitsB && !carry) return 1;
  if(i==N) return 0;

  if(dp[i][bitsA][bitsB][carry]!=-1) return dp[i][bitsA][bitsB][carry];

  ll c=(C&(1<<i))?1:0;
  ll ways=0;

  if(calSum(0,0,carry)==c) ways+=F(i+1,bitsA,bitsB,calCarry(0,0,carry));
  if(calSum(0,1,carry)==c) ways+=F(i+1,bitsA,bitsB-1,calCarry(0,1,carry));
  if(calSum(1,0,carry)==c) ways+=F(i+1,bitsA-1,bitsB,calCarry(1,0,carry));
  if(calSum(1,1,carry)==c) ways+=F(i+1,bitsA-1,bitsB-1,calCarry(1,1,carry));

  dp[i][bitsA][bitsB][carry]=ways;

  return ways;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>A>>B>>C;

    ll bitsA,bitsB;
    bitsA=bitsB=0;

    fr(i,0,N){
      if(A&(1<<i)) bitsA++;
      if(B&(1<<i)) bitsB++;
    }

    MS(dp,-1);

    cout<<F(0,bitsA,bitsB,0)<<"\n";
  }

  return 0;
}
