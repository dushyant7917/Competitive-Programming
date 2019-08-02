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
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll x,y,q;
  string m,n;

  while(t--){
    cin>>m;
    cin>>n;

    cin>>q;

    bool a[SZ(n)+1][SZ(m)+1];

    fr(j,1,SZ(m)+1) a[0][j]=m[j-1]-'0';
    fr(i,1,SZ(n)+1) a[i][0]=n[i-1]-'0';

    for(ll i=1;i<=2 && i<=SZ(n);i++){
      fr(j,1,SZ(m)+1){
        a[i][j]=(!a[i-1][j] || !a[i][j-1]);
      }
    }

    for(ll j=1;j<=2 && j<=SZ(m);j++){
      fr(i,1,SZ(n)+1){
        a[i][j]=(!a[i-1][j] || !a[i][j-1]);
      }
    }

    fr(i,0,q){
      cin>>x>>y;
      if(x>=2 && y>=2) cout<<a[x+2-min(x,y)][y+2-min(x,y)];
      else cout<<a[x][y];
    }

    cout<<"\n";
  }

  return 0;
}
