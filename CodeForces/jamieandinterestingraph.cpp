#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll P=100003,M=1000000000;

  cout<<P<<" "<<P<<"\n";
  cout<<1<<" "<<2<<" "<<P-(n-2)<<"\n";
  fr(i,1,n-1) cout<<i+1<<" "<<i+2<<" "<<1<<"\n";

  ll u=1,v=3;
  fr(i,0,m-(n-1)){
    cout<<u<<" "<<(v++)<<" "<<M<<"\n";
    if(v>n) u++,v=u+2;
  }

  return 0;
}
