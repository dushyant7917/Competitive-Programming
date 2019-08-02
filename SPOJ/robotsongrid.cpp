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
#define mod 2147483647
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
bool visited[N][N];
string a[N];
ll dp[N][N];
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
bool flag=false;

void init(){
  fr(i,0,n){
    fr(j,0,n){
      dp[i][j]=0;
      visited[i][j]=false;
    }
  }
}

bool withinGrid(ll i,ll j){
  if(i<0 || i>=n || j<0 || j>=n) return false;
  else return true;
}

void dfs(ll x,ll y){
  visited[x][y]=true;
  if(x==n-1 && y==n-1){
    flag=true;
    return;
  }

  ll nx,ny;
  fr(i,0,4){
    nx=x+dx[i];
    ny=y+dy[i];
    if(visited[nx][ny] || !withinGrid(nx,ny) || a[nx][ny]=='#') continue;
    dfs(nx,ny);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) cin>>a[i];

  init();
  if(a[0][0]=='.') dfs(0,0);

  fr(i,1,n){
    if(a[i][0]=='#') break;
    else dp[i][0]=1;
  }

  fr(j,1,n){
    if(a[0][j]=='#') break;
    else dp[0][j]=1;
  }

  fr(i,1,n){
    fr(j,1,n){
      if(a[i][j]=='#') continue;

      if(a[i][j-1]=='#' && a[i-1][j]=='.') dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
      if(a[i][j-1]=='.' && a[i-1][j]=='#') dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
      if(a[i][j-1]=='.' && a[i-1][j]=='.') dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%mod;
    }
  }

  if(dp[n-1][n-1]) cout<<dp[n-1][n-1];
  else if(flag) cout<<"THE GAME IS A LIE";
  else cout<<"INCONCEIVABLE";

  return 0;
}
