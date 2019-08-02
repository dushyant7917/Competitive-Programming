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

ll diff(ll a,ll b){
  return (a>=b)?(a-b):0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll h,w;
  cin>>h>>w;

  ll a[h+2][w+2];
  fr(i,0,h+2) fr(j,0,w+2) a[i][j]=0;

  fr(i,1,h+1) fr(j,1,w+1) cin>>a[i][j];

  ll sum=0;
  fr(i,1,h+1) fr(j,1,w+1) {
    sum+=diff(a[i][j],a[i][j-1]);
    sum+=diff(a[i][j],a[i][j+1]);
    sum+=diff(a[i][j],a[i+1][j]);
    sum+=diff(a[i][j],a[i-1][j]);
  }

  cout<<sum+(2*h*w);
  
  return 0;
}
