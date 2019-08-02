#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 51
#define MAX(a,b,c,d,e,f,g,h) max(a,max(b,max(c,max(d,max(e,max(f,max(g,h)))))))
#define MIN(a,b,c) min(min(a,b),c)

ll h,w;
char a[N][N];
ll visited[N][N];
ll nr[8]={-1,-1,-1,0,0,1,1,1};
ll nc[8]={-1,0,1,-1,1,-1,0,1};
ll ans;

void init(){
  fr(i,0,h){
    fr(j,0,w){
      visited[i][j]=0;
      cin>>a[i][j];
    }
  }
}

bool valid(ll r,ll c){
  if(r<0 || c<0 || r>=h || c>=w) return false;
  else return true;
}

ll dfs(ll r,ll c,ll len){
  visited[r][c]=1;
  ans=max(ans,len);

  ll x,y;
  fr(i,0,8){
    x=r+nr[i];
    y=c+nc[i];
    if(!visited[x][y] && valid(x,y) && a[x][y]==a[r][c]+1){
      dfs(x,y,len+1);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t=1;

  while(cin>>h>>w && (h!=0 && w!=0)){
    init();

    ans=0;

    fr(i,0,h){
      fr(j,0,w){
        if(a[i][j]=='A'){
          dfs(i,j,1);
        }
      }
    }

    cout<<"Case "<<(t++)<<": "<<ans<<"\n";
  }

  return 0;
}
