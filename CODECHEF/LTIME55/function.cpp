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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll F(ll x,ll n,ll m=9){
  ll res=1;
  x=x%m;
  while(n>0){
    if(n&1) res=(res*x)%m;
    n>>=1;
    x=(x*x)%m;
  }
  return (res!=0)?res:9;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll a,n;
  while(t--){
    cin>>a>>n;
    cout<<F(a,n,9)<<"\n";
  }

  return 0;
}
