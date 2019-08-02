#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 5001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n1,n2;
string a,b;
ll dp[2][N][N];
ll suff1[N],suff2[N];

ll cal(ll f,ll s,ll i,ll j){
  if(f==0 && s==0){
    return (a[i-1]==a[i])?0:1;
  }
  if(f==0 && s==1){
    return (a[i-1]==b[j])?0:1;
  }
  if(f==1 && s==1){
    return (b[j-1]==b[j])?0:1;
  }
  if(f==1 && s==0){
    return (b[j-1]==a[i])?0:1;
  }
}

ll F(ll c,ll i,ll j){
  if(i<=n1-1 && j>=n2) return ((a[i]==b[n2-1])?0:1)+suff1[i];
  else if(i>=n1 && j<=n2-1) return ((a[n1-1]==b[j])?0:1)+suff2[j];
  else{
    if(dp[c][i][j]==-1) dp[c][i][j]=min(cal(c,1,i,j)+F(1,i,j+1),cal(c,0,i,j)+F(0,i+1,j));
    return dp[c][i][j];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n1>>n2;
    cin>>a>>b;

    suff1[n1-1]=0;
    for(ll i=n1-2;i>=0;i--){
      if(a[i]==a[i+1]) suff1[i]=0+suff1[i+1];
      else suff1[i]=1+suff1[i+1];
    }
    suff2[n2-1]=0;
    for(ll i=n2-2;i>=0;i--){
      if(b[i]==b[i+1]) suff2[i]=0+suff2[i+1];
      else suff2[i]=1+suff2[i+1];
    }

    fr(k,0,2) fr(i,0,n1+1) fr(j,0,n2+1) dp[k][i][j]=-1;
    ll a1=F(0,1,0);
    ll a2=F(1,0,1);
    cout<<min(a1,a2)+1<<"\n";
  }

  return 0;
}
