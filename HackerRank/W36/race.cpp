#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e16
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll h[n+1],p[n+1];
  fr(i,1,n+1) cin>>h[i];
  fr(i,2,n+1) cin>>p[i];

  ll dp[n+1],x;
  stack<pii> st;


  rf(i,n,0){
    dp[i]=INF;
    x=INF;

    while(st.size() && h[st.top().first]<=h[i]){
      dp[i]=min(dp[i],st.top().second-i+h[i]);
      x=min(x,st.top().second);
      st.pop();
    }

    if(!st.size()){
      dp[i]=min(dp[i],n-i+1);
    }
    else{
      dp[i]=min(dp[i],dp[st.top().first]+st.top().first-i+h[st.top().first]-h[i]+p[st.top().first]);
    }

    x=min(x,dp[i]+i-h[i]+p[i]);
    st.push(pii(i,x));
  }

  cout<<dp[1];

  return 0;
}
