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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll dist[n+1][n+1],v[n+1],ans[n+1]={0};

  fr(i,1,n+1) fr(j,1,n+1) cin>>dist[i][j];
  fr(i,1,n+1) cin>>v[i];

  rf(k,n,1){
    fr(i,1,n+1){
      fr(j,1,n+1){
        dist[i][j]=min(dist[i][j],dist[i][v[k]]+dist[v[k]][j]);
      }
    }

    fr(i,k,n+1){
      fr(j,k,n+1){
        ans[k]+=dist[v[i]][v[j]];
      }
    }
  }

  fr(i,1,n+1) cout<<ans[i]<<" ";

  return 0;
}
