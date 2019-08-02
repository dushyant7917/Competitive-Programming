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
#define N 501
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)



int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>h>>w;

  fr(i,0,h){
    fr(j,0,w){
      cin>>a[i][j];
    }
  }

  ll ans=fn(0,0,2,1,3);
  fr(j,1,w){
    ans=max(ans,fn(0,j,2,1,3));
  }
  cout<<ans<<"\n";

  return 0;
}
