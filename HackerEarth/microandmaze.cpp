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

ll n,m;
ll a[100][100];
bool visited[100][100];

void initialize(){
  fr(i,0,100) fr(j,0,100) visited[i][j]=false;
}

bool dfs(ll x,ll y,ll dx,ll dy){
  if(x==dx && y==dy) return true;
  if(x<0 || y<0) return false;
  if(x>n-1 || y>m-1) return false;
  if(a[x][y]==0) return false;
  if(visited[x][y]) return false;
  visited[x][y]=true;
  if(dfs(x+1,y,dx,dy)) return true;
  if(dfs(x-1,y,dx,dy)) return true;
  if(dfs(x,y+1,dx,dy)) return true;
  if(dfs(x,y-1,dx,dy)) return true;

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>m;

  fr(i,0,n) fr(j,0,m) cin>>a[i][j];

  initialize();

  if(dfs(0,0,n-1,m-1)) cout<<"Yes";
  else cout<<"No";

  return 0;
}
