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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll a[n+1][m+1],ms[n+1][m+1];
  fr(i,1,n+1) fr(j,1,m+1) cin>>a[i][j];

  ms[1][1]=a[1][1];

  fr(i,2,n+1) ms[i][1]=ms[i-1][1]+a[i][1];
  fr(j,2,m+1) ms[1][j]=ms[1][j-1]+a[1][j];

  fr(i,2,n+1) fr(j,2,m+1) ms[i][j]=ms[i][j-1]+ms[i-1][j]-ms[i-1][j-1]+a[i][j];

  ll q;
  cin>>q;

  ll x,y;
  while(q--){
    cin>>x>>y;
    cout<<ms[x][y]<<"\n";
  }

  return 0;
}
