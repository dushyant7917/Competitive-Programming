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

ll n;
char d;
ll p[60][60];
bool visited[60][60];

void initialize(){
  fr(i,0,n) fr(j,0,n) visited[i][j]=false;
}

ll t=0;

bool move(ll x,ll y){
  if(t==n*n) return true;
  if(x<0 || y<0) return false;
  if(x>=n || y>=n) return false;
  if(visited[x][y]==true) return false;
  visited[x][y]=true;
  p[x][y]=++t;
  if(d=='e'){
    if(move(x,y+1)) return true;
    if(move(x+1,y)) return true;
    if(move(x-1,y)) return true;
    if(move(x,y-1)) return true;
  }
  else if(d=='w'){
    if(move(x,y-1)) return true;
    if(move(x+1,y)) return true;
    if(move(x-1,y)) return true;
    if(move(x,y+1)) return true;
  }
  else if(d=='n'){
    if(move(x-1,y)) return true;
    if(move(x,y+1)) return true;
    if(move(x,y-1)) return true;
    if(move(x+1,y)) return true;
  }
  else{
    if(move(x+1,y)) return true;
    if(move(x,y+1)) return true;
    if(move(x,y-1)) return true;
    if(move(x-1,y)) return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;

  cin>>d;

  ll x,y;
  cin>>x>>y;

  initialize();
  if(move(x,y)==true){
    fr(i,0,n){
      fr(j,0,n) cout<<p[i][j]<<" ";
      cout<<"\n";
    }
  }

  return 0;
}
