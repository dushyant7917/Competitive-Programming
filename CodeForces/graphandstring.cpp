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
#define N 501
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool adj[N][N];
char mark[N];
ll deg[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  MS(adj,false);
  MS(deg,0);
  ll u,v;

  fr(i,0,m){
    cin>>u>>v;
    adj[u][v]=true;
    adj[v][u]=true;
    deg[u]++;
    deg[v]++;
  }

  MS(mark,'c');

  fr(i,1,n+1) if(deg[i]==n-1) mark[i]='b';

  fr(i,1,n+1){
    if(mark[i]=='c'){
      mark[i]='a';
      fr(j,1,n+1){
        if(i!=j && adj[i][j] && mark[j]!='b'){
          mark[j]='a';
        }
      }
      break;
    }
  }

  bool flag=true;

  fr(i,1,n+1){
    fr(j,1,n+1){
      if(i==j) continue;
      else if(adj[i][j] && mark[i]=='a' && mark[j]=='c') flag=false;
      else if(adj[i][j] && mark[i]=='c' && mark[j]=='a') flag=false;
      else if(!adj[i][j] && mark[i]=='b' && mark[j]=='b') flag=false;
      else if(!adj[i][j] && mark[i]=='a' && mark[j]=='a') flag=false;
      else if(!adj[i][j] && mark[i]=='c' && mark[j]=='c') flag=false;
      else if(!adj[i][j] && mark[i]=='a' && mark[j]=='b') flag=false;
      else if(!adj[i][j] && mark[i]=='b' && mark[j]=='a') flag=false;
      else {}
      if(!flag) break;
    }
    if(!flag) break;
  }

  if(flag){
    cout<<"Yes\n";
    fr(i,1,n+1) cout<<mark[i];
  }
  else cout<<"No\n";

  return 0;
}
