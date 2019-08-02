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
#define sz(s) s.size()

ll n1,n2;
string a,b,aa,bb;
ll dp[5001][5001];

ll lcs(ll x,ll y){
  fr(i,0,x+1){
    fr(j,0,y+1){
      if(!i || !j) dp[i][j]=0;
      else if(aa[i-1]==bb[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[x][y];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  char prv;
  while(t--){
    cin>>n1>>n2;
    cin>>a>>b;

    aa=bb="";
    prv=a[0];
    aa+=prv;
    fr(i,1,sz(a)){
      if(a[i]!=prv) aa+=a[i];
      prv=a[i];
    }
    prv=b[0];
    bb+=prv;
    fr(i,1,sz(b)){
      if(b[i]!=prv) bb+=b[i];
      prv=b[i];
    }

    fr(i,0,n1+1) fr(j,0,n2+1) dp[i][j]==-1;

    cout<<sz(aa)+sz(bb)-lcs(sz(aa),sz(bb))<<"\n";
  }

  return 0;
}
