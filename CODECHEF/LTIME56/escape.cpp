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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll a[N][N];
bool visited[N][N];
ll nr[4]={-1,0,1,0};
ll nc[4]={0,1,0,-1};

void init(){
  fr(i,0,n) fr(j,0,m) visited[i][j]=false;
}

bool valid(ll x,ll y){
  if(visited[x][y] || x<0 || x>=n || y<0 || y>=m || a[x][y]==-1) return false;
  else return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    init();

    vector<pii> e[N];

    fr(i,0,n){
      fr(j,0,m){
        cin>>a[i][j];
        if(a[i][j]>0) e[a[i][j]].PB(MP(i,j));
      }
    }

    ll x,y;
    rf(i,1000,0){
      fr(j,0,SZ(e[i])){
        x=e[i][j].first;
        y=e[i][j].second;

        if(visited[x][y]) continue;
        else visited[x][y]=true;

        fr(k,0,4){
          if(valid(x+nr[k],y+nc[k])) e[i-1].PB(MP(x+nr[k],y+nc[k]));
        }
      }
    }

    fr(i,0,SZ(e[0])){
      x=e[0][i].first;
      y=e[0][i].second;
      visited[x][y]=true;
    }

    fr(i,0,n){
      fr(j,0,m){
        if(a[i][j]==-1) cout<<'B';
        else{
          if(visited[i][j]) cout<<'Y';
          else cout<<'N';
        }
      }
      cout<<"\n";
    }
    //cout<<"\n";
  }

  return 0;
}
