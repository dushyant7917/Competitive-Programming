#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 401
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool rail[N][N];
bool road[N][N];
bool visited[N];

ll bfs(ll network){
  ll dist[n+1];
  fr(i,0,n+1) dist[i]=INF;
  dist[1]=0;

  queue<ll> q;
  q.push(1);

  ll v;
  while(q.size()){
    v=q.front();
    q.pop();

    fr(u,1,n+1){
      if(network==1 && rail[v][u] && dist[v]+1<dist[u]){
        dist[u]=dist[v]+1;
        q.push(u);
      }
      if(network==2 && road[v][u] && dist[v]+1<dist[u]){
        dist[u]=dist[v]+1;
        q.push(u);
      }
    }
  }

  return dist[n];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  MS(rail,false);
  MS(road,false);

  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    rail[x][y]=rail[y][x]=true;
  }

  fr(i,1,n+1){
    fr(j,1,n+1){
      if(i!=j){
        road[i][j]=!rail[i][j];
      }
    }
  }

  ll s1,s2;
  MS(visited,false);
  s1=bfs(1);
  MS(visited,false);
  s2=bfs(2);
  if(s1==INF || s2==INF) cout<<-1;
  else cout<<max(s1,s2);

  return 0;
}
