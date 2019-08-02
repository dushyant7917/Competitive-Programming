#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
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

ll n,k,m;
bool visited[N][N];
ll deg[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>k;

  m=0;
  MS(visited,false);
  MS(deg,0);

  fr(i,1,n+1){
    fr(j,1,n+1){
      if(i==j) continue;
      if(visited[i][j] || visited[j][i]) continue;
      if(deg[i]==k) continue;
      deg[i]++;
      m++;
      visited[i][j]=true;
    }
  }

  fr(i,1,n+1){
    if(deg[i]==k) continue;
    cout<<-1;
    return 0;
  }

  cout<<m<<"\n";
  fr(i,1,n+1){
    fr(j,1,n+1){
      if(visited[i][j]) cout<<i<<" "<<j<<"\n";
    }
  }

  return 0;
}
