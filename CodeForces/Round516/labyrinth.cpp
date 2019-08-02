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
#define N 2001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,sr,sc,lL,rR;
bool visited[N][N];
string s[N];
ll nr[4]={-1,1,0,0};
ll nc[4]={0,0,-1,1};

struct Node{
  ll r,c,x,y;
};

bool valid(ll r,ll c){
  if(r<0 || r>=n || c<0 || c>=m) return false;

  return true;
}

void bfs(){
  deque<Node> q;
  q.push_front({sr,sc,0,0});
  visited[sr][sc]=true;

  ll r,c,x,y;
  while(SZ(q)){
    r=q.front().r;
    c=q.front().c;
    x=q.front().x;
    y=q.front().y;
    q.pop_front();

    fr(i,0,4){
      if(!valid(r+nr[i],c+nc[i])) continue;
      if(visited[r+nr[i]][c+nc[i]]) continue;
      if(s[r+nr[i]][c+nc[i]]=='*') continue;
      if(x==lL && i==2) continue;
      if(y==rR && i==3) continue;

      visited[r+nr[i]][c+nc[i]]=true;

      if(i==2) q.push_back({r+nr[i],c+nc[i],x+1,y});
      if(i==3) q.push_back({r+nr[i],c+nc[i],x,y+1});
      if(i<=1) q.push_front({r+nr[i],c+nc[i],x,y});
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  cin>>sr>>sc;
  cin>>lL>>rR;

  fr(i,0,n) cin>>s[i];

  sr--;
  sc--;

  fr(i,0,n) fr(j,0,m) visited[i][j]=false;
  bfs();

  ll ans=0;

  fr(i,0,n){
    fr(j,0,m){
      if(!visited[i][j]) continue;
      ans++;
    }
  }

  cout<<ans;

  return 0;
}
