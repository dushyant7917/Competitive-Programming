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
#define N 1000
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll a[N][N];
char b[N][N];
ll nr[4]={-1,0,1,0};
ll nc[4]={0,1,0,-1};
ll tim;
bool visited[N][N];

bool valid(ll x,ll y){
  if(x<0 || x>=n || y<0 || y>=m || a[x][y]==-1) return false;
  else return true;
}

void init(){
  fr(i,0,n) fr(j,0,m) visited[i][j]=false;
}

void F(ll r,ll c,ll t){
  if(t>tim){
    return;
  }

  if(t<=tim){
    b[r][c]='Y';
    visited[r][c]=true;
    ll x,y;
    fr(i,0,4){
      x=r+nr[i];
      y=c+nc[i];

      if(valid(x,y) && (t+1)<=tim && !visited[x][y]) F(x,y,t+1);
    }
  }
}

bool cmp(pair<pair<ll,ll>,ll> e1,pair<pair<ll,ll>,ll> e2){
  return e1.second>e2.second;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    fr(i,0,n) fr(j,0,m) b[i][j]='N';

    vector<pair<pair<ll,ll>,ll> > e;

    fr(i,0,n){
      fr(j,0,m){
        cin>>a[i][j];
        if(a[i][j]==-1) b[i][j]='B';
        if(a[i][j]>0) e.PB(MP(MP(i,j),a[i][j]));
      }
    }

    sort(e.begin(),e.end(),cmp);

    init();

    fr(i,0,SZ(e)){
      tim=e[i].second;
      F(e[i].first.first,e[i].first.second,0);
      //cout<<"\n";
    }

    fr(i,0,n){
      fr(j,0,m){
        cout<<b[i][j];
      }
      cout<<"\n";
    }
    cout<<"\n";
  }

  return 0;
}
