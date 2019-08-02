#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 501
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,k;
ll dp[N][N][N];
ll a[N][N];
ll lm[N][N];
ll rm[N][N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m>>k;

  char c;
  fr(i,0,n){
    fr(j,0,m){
      cin>>c;
      if(c=='0') a[i][j]=0;
      else a[i][j]=1;
    }
  }

  fr(i,0,n){
    fr(j,0,m){
      if(a[i][j]){
        fr(k,0,m){
          if(a[i][k]) 
        }
      }
    }
  }

  return 0;
}
