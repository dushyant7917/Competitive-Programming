#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 4001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool adj[N][N];
ll edge[N][2];
ll degree[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  MS(adj,false);
  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    edge[i][0]=x;
    edge[i][1]=y;
    adj[x][y]=true;
    adj[y][x]=true;
  }

  MS(degree,0);
  fr(i,1,n+1){
    fr(j,1,n+1){
      if(adj[i][j]) degree[i]++;
    }
  }

  ll ans=INF;
  fr(i,0,m){
    x=edge[i][0];
    y=edge[i][1];
    fr(z,1,n+1){
      if(z!=x && z!=y && adj[x][z] && adj[y][z]){
        ans=min(ans,degree[x]+degree[y]+degree[z]-6);
      }
    }
  }

  if(ans!=INF) cout<<ans;
  else cout<<-1;

  return 0;
}
