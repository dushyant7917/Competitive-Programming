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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll dist[N][N];

void init(){
  fr(i,0,n) fr(j,0,n) dist[i][j]=INF;
}

void floydWarshall(){
  fr(k,0,n) fr(i,0,n) fr(j,0,n) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  ll x;
  bool flag;
  while(1){
    cin>>n;

    if(!n) break;

    init();

    fr(i,0,n){
      cin>>x>>s;
      x--;
      if(s=="true") dist[i][x]=2;
      else dist[i][x]=1;
    }

    floydWarshall();

    flag=true;

    fr(i,0,n){
      if(dist[i][i]&1){
        flag=false;
        break;
      }
    }

    if(flag) cout<<"NOT PARADOX\n";
    else cout<<"PARADOX\n";
  }

  return 0;
}
