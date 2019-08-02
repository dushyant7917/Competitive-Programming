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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
string a[N];
pii src,dst;
ll dist[N][N];
ll dx[]={1,-1,0,0,1,-1,-1,1};
ll dy[]={0,0,1,-1,1,-1,1,-1};

void init(){
  fr(i,0,n) fr(j,0,m) dist[i][j]=-1;
}

bool withinGrid(ll i,ll j){
  if(i<0 || i>=n || j<0 || j>=m) return false;
  else return true;
}

void bfs(){
  queue<pii> q;
  dist[src.fi][src.se]=0;
  q.push(src);

  ll x,y,nx,ny;
  while(SZ(q)){
    x=q.front().fi;
    y=q.front().se;
    q.pop();

    fr(i,0,8){
      nx=x+dx[i];
      ny=y+dy[i];
      while(withinGrid(nx,ny) && a[nx][ny]!='X'){
        if(dist[nx][ny]==-1){
          dist[nx][ny]=dist[x][y]+1;
          q.push(pii(nx,ny));
        }
        else if(dist[nx][ny]!=dist[x][y]+1) break;
        else {}

        nx+=dx[i];
        ny+=dy[i];
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    fr(i,0,n){
      cin>>a[i];
      fr(j,0,m){
        if(a[i][j]=='S'){
          src.fi=i;
          src.se=j;
        }
        if(a[i][j]=='F'){
          dst.fi=i;
          dst.se=j;
        }
      }
    }

    init();
    bfs();

    if(dist[dst.fi][dst.se]==-1) cout<<-1<<"\n";
    else cout<<dist[dst.fi][dst.se]<<"\n";
  }

  return 0;
}
