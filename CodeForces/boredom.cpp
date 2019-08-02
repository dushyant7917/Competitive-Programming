#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll freq[100001]={};
ll dp[100001]={};

ll solve(ll num){
  fr(i,0,num+1){
    if(i<=1) dp[i]=freq[i];
    else{
      dp[i]=max(dp[i-1],i*freq[i]+dp[i-2]);
    }
  }
  return dp[num];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  ll max_num=0;
  fr(i,0,n){
    cin>>a[i];
    freq[a[i]]++;
    max_num=max(max_num,a[i]);
  }

  cout<<solve(max_num);

  return 0;
}
