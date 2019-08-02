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
#define N 20001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll dp[N];

bool mutiple_two(ll x){
    if(x==0) return false;
    return (!(x & (x-1)));
}

void init(){
  dp[1]=1;
  fr(i,2,N){
    if(mutiple_two(i)) dp[i]=dp[i-1]+1;
    else dp[i]=dp[i-1];
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();

  ll n;
  while(cin>>n && n!=0){
    cout<<dp[n]-1<<"\n";
  }

  return 0;
}
