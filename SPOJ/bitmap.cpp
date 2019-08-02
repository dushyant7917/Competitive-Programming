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
#define N 182
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,m;
ll a[N][N];
ll md[N][N];
ll adj[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void bfs(ll r,ll c){
  queue<pair<ll,ll> > q;
  q.push(MP(r,c));
  pair<ll,ll> node;
  md[r][c]=0;
  ll dist;

  while(!q.empty()){
    node=q.front();
    q.pop();
    dist=md[node.first][node.second]+1;

    ll x,y;
    fr(i,0,4){
      x=node.first+adj[i][0];
      y=node.second+adj[i][1];
      if(x<0 || x>=n || y<0 || y>=m){
        // node not in graph
      }
      else{
        if(dist<md[x][y]){
          md[x][y]=dist;
          q.push(MP(x,y));
        }
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

  string row;
  while(t--){
    cin>>n>>m;

    fr(i,0,n){
      cin>>row;
      fr(j,0,m){
        a[i][j]=row[j]-'0';
        if(a[i][j]==1) md[i][j]=-INF;
        else md[i][j]=INF;
      }
    }

    fr(i,0,n){
      fr(j,0,m){
        if(a[i][j]==1){
          bfs(i,j);
        }
      }
    }

    fr(i,0,n){
      fr(j,0,m){
        cout<<md[i][j]<<" ";
      }
      cout<<"\n";
    }
  }

  return 0;
}
