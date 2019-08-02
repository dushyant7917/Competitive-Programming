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

ll budget,n;

/*
ll max_fun(ll fee[],ll fun[],ll i,ll d){
  if(i>=n || d==0) return 0;
  else if(fee[i]>d){
    return max_fun(fee,fun,i+1,d);
  }
  else{
    return max(fun[i]+max_fun(fee,fun,i+1,d-fee[i]),max_fun(fee,fun,i+1,d));
  }
}
*/

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(cin>>budget>>n && (budget!=0 && n!=0)){
    ll fee[n+1],fun[n+1];
    fr(i,1,n+1) cin>>fee[i]>>fun[i];

    ll dp[n+1][budget+1];
    fr(i,0,n+1){
      fr(j,0,budget+1){ // j represents budget limit
        if(i==0 || j==0){
          dp[i][j]=0; // no budget and no fee
        }
        else if(fee[i]>j){
          dp[i][j]=dp[i-1][j]; // fee of current party is less than budget limit hence it can't be included
        }
        else{
          dp[i][j]=max(dp[i-1][j],fun[i]+dp[i-1][j-fee[i]]); // fun calculated when (i)th party is included/excluded
        }
      }
    }

    ll cost;
    fr(j,1,budget+1){
      if(dp[n][j]==dp[n][budget]){
        cost=j;
        break;
      }
    }

    cout<<cost<<" "<<dp[n][budget]<<"\n";
  }

  return 0;
}
