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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m,k;
  cin>>n>>m>>k;

  ll a[n][n];

  fr(i,0,n){
    fr(j,0,n){
      if(!i && !j) a[i][j]=m;
      else if(i==j) a[i][j]=a[i-1][j-1]+k;
      else if(i>j) a[i][j]=a[i-1][j]-1;
      else a[i][j]=a[i][j-1]-1;
    }
  }

  fr(i,0,n){
    fr(j,0,n){
      cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
