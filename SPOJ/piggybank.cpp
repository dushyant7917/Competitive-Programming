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
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll e,f,c,n;
  while(t--){
    cin>>e>>f;
    c=f-e;

    cin>>n;
    ll val[n],wt[n];
    fr(i,0,n){
      cin>>val[i]>>wt[i];
    }

    ll dp[c+1];
    dp[0]=0;

    fr(w,1,c+1){
      dp[w]=INF;
      fr(i,0,n){
        if(wt[i]<=w && dp[w-wt[i]]!=INF){
          dp[w]=min(dp[w],dp[w-wt[i]]+val[i]);
        }
      }
    }


    if(dp[c]!=INF){
      cout<<"The minimum amount of money in the piggy-bank is "<<dp[c]<<".\n";
    }
    else{
      cout<<"This is impossible.\n";
    }


  }

  return 0;
}
