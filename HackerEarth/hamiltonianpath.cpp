#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
bool adj[N][N];
ll v[N];

bool check(){
  bool flag;

  do{
    flag=true;
    fr(i,0,n-1){
      if(!adj[v[i]][v[i+1]]){
        flag=false;
        break;
      }
    }
    if(flag) return true;
  }while(next_permutation(v,v+n));

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  fr(i,0,n) v[i]=i;

  MS(adj,false);
  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    adj[x][y]=true;
    adj[y][x]=true;
  }

  if(check()) cout<<"YES";
  else cout<<"NO";

  return 0;
}
