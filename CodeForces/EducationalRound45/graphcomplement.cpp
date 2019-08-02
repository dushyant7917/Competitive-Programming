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

  ll n,a,b,c;
  cin>>n>>a>>b;

  ll g[n+1][n+1];
  fr(i,1,n+1) fr(j,1,n+1) g[i][j]=0;

  if(min(a,b)>1) cout<<"NO";
  else if(a==1 && b==1 && (n==2 || n==3)) cout<<"NO";
  else{
    c=max(a,b);
    fr(i,1,n-c+1){
      g[i][i+1]=1;
      g[i+1][i]=1;
    }

    if(a==1){
      fr(i,1,n+1){
        fr(j,1,n+1){
          if(i==j) continue;
          if(g[i][j]) g[i][j]=0;
          else g[i][j]=1;
        }
      }
    }

    cout<<"YES\n";
    fr(i,1,n+1){
      fr(j,1,n+1){
        cout<<g[i][j];
      }
      cout<<"\n";
    }
  }

  return 0;
}
