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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;
ll sx,sy,ex,ey;
vector<ll> graph[N*N];
ll visited[N*N]={0};
char a[N][N];
ll dist[N*N];
ll nr[4]={-1,0,1,0};
ll nc[4]={0,1,0,-1};

void init(){
  fr(i,0,N*N) dist[i]=INF;
}

bool valid(ll x,ll y){
  if(x<0 || y<0 || x>=n || y>=n) return false;
  if(a[x][y]=='X') return false;
  return true;
}

void bfs(){
  queue<ll> q;
  q.push(sx*n+sy);
  dist[sx*n+sy]=0;
  visited[sx*n+sy]=1;

  ll node,v;
  while(q.size()){
    node=q.front();
    q.pop();
    fr(i,0,graph[node].size()){
      v=graph[node][i];
      if(visited[v]==0){
        visited[v]=1;
        dist[v]=dist[node]+1;
        q.push(v);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) fr(j,0,n) cin>>a[i][j];
  cin>>sx>>sy>>ex>>ey;

  ll p,q;
  fr(i,0,n){
    fr(j,0,n){
      if(a[i][j]!='X'){
        fr(k,0,4){
          p=i;
          q=j;
          while(valid(p+nr[k],q+nc[k])){
            p+=nr[k];
            q+=nc[k];
            graph[i*n+j].PB(p*n+q);
          }
        }
      }
    }
  }

  init();
  bfs();
  cout<<dist[ex*n+ey];

  return 0;
}
