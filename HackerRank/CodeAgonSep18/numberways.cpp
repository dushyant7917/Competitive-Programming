#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
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

string a,b,c;
ll dp[301][301][301];

ll F(ll i,ll j,ll k){
  if(i+j>SZ(c)) return 0;
  if(i>=SZ(a) && j>=SZ(b) && k!=SZ(c)) return 0;
  if(k==SZ(c) && i && j) return 1;

  ll x,y,z;
  x=y=z=0;

  if(i<SZ(a) && a[i]==c[k]) x+=F(i+1,j,k+1)%mod;
  if(j<SZ(b) && b[j]==c[k]) y+=F(i,j+1,k+1)%mod;
  z+=F(i+1,j+1,k)%mod;

  return (x+y+z)%mod;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>a>>b>>c;
  cout<<F(0,0,0);

  return 0;
}
