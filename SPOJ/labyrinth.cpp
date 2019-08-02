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

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
ll r,c;
bool visited[N][N];
string a[N];
pii src,leaf;

void init(){
  fr(i,0,r){
    fr(j,0,c){
      visited[i][j]=false;
    }
  }
}

bool valid(ll i,ll j){
  if(i<0 || i>=r || j<0 || j>=c) return false;
  else return true;
}

ll ans;

void dfs(pii p,ll len){
  ll x=p.fi;
  ll y=p.se;
  visited[x][y]=true;

  if(len>ans){
    leaf.fi=x;
    leaf.se=y;
    ans=len;
  }

  ll nx,ny;
  fr(i,0,4){
    nx=x+dx[i];
    ny=y+dy[i];
    if(valid(nx,ny) && !visited[nx][ny] && a[nx][ny]=='.') dfs(pii(nx,ny),len+1);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>c>>r;

    fr(i,0,r){
      cin>>a[i];
      fr(j,0,c){
        if(a[i][j]=='.'){
          src.fi=i;
          src.se=j;
        }
      }
    }


    init();
    ans=0;
    dfs(src,0);
    init();
    ans=0;
    dfs(leaf,0);
    cout<<"Maximum rope length is "<<ans<<".\n";
  }

  return 0;
}
